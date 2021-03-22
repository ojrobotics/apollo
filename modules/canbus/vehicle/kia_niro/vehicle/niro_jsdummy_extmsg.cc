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

#include "modules_syn/msg_niro/proto/chassis_status.pb.h"

#include "cyber/cyber.h"
#include "cyber/time/rate.h"
#include "cyber/time/time.h"

#define COMMANDER_UPDATE_INTERVAL_MICRO (50000)
#define SLEEP_TICK_INTERVAL_MICRO (1000)

using apollo::cyber::Rate;
using apollo::cyber::Time;
using apollo::modules_syn::msg_niro::proto::NiroStatus;

static int error_thrown = OSCC_OK;

// static unsigned long long get_timestamp_micro()
// {
//   struct timeval time;
//   gettimeofday(&time, NULL);
//   return (time.tv_usec);
// }

// static unsigned long long get_elapsed_time( unsigned long long timestamp)
// {
//   unsigned long long now = get_timestamp_micro( );
//   unsigned long long elapsed_time = now - timestamp;
//   return elapsed_time;
// }

void signal_handler(int signal_number)
{
  if (signal_number == SIGINT)
    error_thrown = OSCC_ERROR;
}

int main(int argc, char** argv) 
{
  oscc_result_t result = OSCC_OK;
  // unsigned long long update_timestamp = get_timestamp_micro();
  // unsigned long long elapsed_time = 0;
  int channel = 1;
  errno = 0;

  struct sigaction sig;
  sig.sa_handler = signal_handler;
  sigaction(SIGINT, &sig, NULL);
  result = commander_init(channel);

  // init cyber framework
  apollo::cyber::Init(argv[0]);
  // create talker node
  auto talker_node = apollo::cyber::CreateNode("niro_chassis_talker");
  double frequency = 32;
  Rate rate(frequency);
  // create talker
  auto talker = talker_node->CreateWriter<NiroStatus>("niro/chassis_status");

  if (result == OSCC_OK)
  {
    printf("\nNode - niro_streaming_status start\n");

    uint64_t seq = 0;
    while (result == OSCC_OK 
           && error_thrown == OSCC_OK
           && apollo::cyber::OK()     )
    {
      // elapsed_time = get_elapsed_time(update_timestamp);
      // if (elapsed_time > COMMANDER_UPDATE_INTERVAL_MICRO)
      // {
        // update_timestamp = get_timestamp_micro();
        result = check_for_controller_update();
        auto msg = std::make_shared<NiroStatus>();
        msg->set_timestamp(Time::Now().ToNanosecond());
        msg->set_seq(seq);
        msg->set_steering_angle(g_steering_angle);
        msg->set_brake_pressure(g_brake_pressure);
        talker->Write(msg);
        AINFO << "Sent a status message from Niro to Apollo! No. " << seq;
        seq++;
        rate.Sleep();
      // }

      // Delay 1 ms to avoid loading the CPU
      // (void)usleep(SLEEP_TICK_INTERVAL_MICRO);
    }
    commander_close(channel);
    printf("\nNode - niro_streaming_status stop.\n");
  }




  // Rate rate(1.);
  // uint64_t seq = 0;
  // while (apollo::cyber::OK()) {
  //   auto msg = std::make_shared<NiroStatus>();
  //   msg->set_timestamp(Time::Now().ToNanosecond());
  //   msg->set_seq(seq);
  //   msg->set_steering_angle(g_steering_angle);
  //   msg->set_brake_pressure(g_brake_pressure);
  //   talker->Write(msg);
  //   AINFO << "Sent a status message from Niro to Apollo! No. " << seq;
  //   seq++;
  //   rate.Sleep();
  // }
  return 0;
}
