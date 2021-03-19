#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <fcntl.h>

#include "oscc.h"
#include "commander.h"
#include "can_protocols/steering_can_protocol.h"

//#include "modules/canbus/vehicle/kia_niro/msg_niro/proto/chassis_command.pb.h"
//#include "modules/canbus/vehicle/kia_niro/msg_niro/proto/chassis_status.pb.h"
#include "modules/canbus/proto/kia_niro.pb.h"

#include "cyber/cyber.h"
#include "cyber/time/rate.h"
#include "cyber/time/time.h"

#define COMMANDER_UPDATE_INTERVAL_MICRO (50000)
#define SLEEP_TICK_INTERVAL_MICRO (1000)

using apollo::cyber::Rate;
using apollo::cyber::Time;
//using apollo::canbus::msg_niro::proto::NiroCommand;
using apollo::canbus::Kia_niro;

static int error_thrown = OSCC_OK;

void signal_handler(int signal_number)
{
  if (signal_number == SIGINT)
    error_thrown = OSCC_ERROR;
}

void MessageCallback(
    const std::shared_ptr<apollo::canbus::Kia_niro>& msg)
{
  double steering_angle = msg->mutable_nirocommand()->steering_angle();
  double pedal_position = msg->mutable_nirocommand()->pedal_position();
  double throttle_position = msg->mutable_nirocommand()->throttle_position();
  AINFO << "Received message seq-> " << msg->mutable_nirocommand()->steering_angle();
  AINFO << "msgcontent->" << msg->mutable_nirocommand()->pedal_position();
  oscc_publish_brake_position(pedal_position);
  oscc_publish_steering_torque(steering_angle);
  oscc_publish_throttle_position(throttle_position);
  // check_for_controller_update();
}

int main(int argc, char** argv)
{
  oscc_result_t result = OSCC_OK;
  int can_channel = 0;
  errno = 0;

  struct sigaction sig;
  sig.sa_handler = signal_handler;
  sigaction(SIGINT, &sig, NULL);
  result = commander_init(can_channel);
  oscc_enable();

  apollo::cyber::Init(argv[0]);
  // auto talker_node = apollo::cyber::CreateNode("niro_chassis_talker");
  auto listener_node = apollo::cyber::CreateNode("niro_listenser");
  auto listener =
      listener_node->CreateReader<apollo::canbus::Kia_niro>(    // Omar check this ::NiroCommand
          "niro/chassis_command", MessageCallback);


  double frequency = 32;
  Rate rate(frequency);
  // auto talker = talker_node->CreateWriter<NiroCommand>("niro/chassis_status");

  if (result == OSCC_OK)
  {
    printf("\nNode - niro_listening_command start.\n");

    // // uint64_t seq = 0;
    // while (result == OSCC_OK
    //        && error_thrown == OSCC_OK
    //        && apollo::cyber::OK()     )
    // {
    //     result = check_for_controller_update();
    //     // auto msg = std::make_shared<NiroStatus>();
    //     // msg->set_timestamp(Time::Now().ToNanosecond());
    //     // msg->set_seq(seq);
    //     // msg->set_steering_angle(g_steering_angle);
    //     // msg->set_brake_pressure(g_brake_pressure);
    //     // talker->Write(msg);
    //     // AINFO << "Sent a status message from Niro to Apollo! No. " << seq;
    //     // seq++;
    //     rate.Sleep();
    // }

    apollo::cyber::WaitForShutdown();
    commander_close(can_channel);
    printf("\nNode - niro_streaming_status stop.\n");
  }

  return 0;
}
