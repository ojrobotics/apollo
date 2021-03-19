/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include "modules/canbus/vehicle/kia_niro/kia_niro_message_manager.h"

#include "modules/canbus/vehicle/kia_niro/protocol/accel_6b.h"
#include "modules/canbus/vehicle/kia_niro/protocol/brake_60.h"
#include "modules/canbus/vehicle/kia_niro/protocol/brake_61.h"
#include "modules/canbus/vehicle/kia_niro/protocol/brakeinfo_74.h"
#include "modules/canbus/vehicle/kia_niro/protocol/fuellevel_72.h"
#include "modules/canbus/vehicle/kia_niro/protocol/gear_66.h"
#include "modules/canbus/vehicle/kia_niro/protocol/gear_67.h"
#include "modules/canbus/vehicle/kia_niro/protocol/gps_6d.h"
#include "modules/canbus/vehicle/kia_niro/protocol/gps_6e.h"
#include "modules/canbus/vehicle/kia_niro/protocol/gps_6f.h"
#include "modules/canbus/vehicle/kia_niro/protocol/gyro_6c.h"
#include "modules/canbus/vehicle/kia_niro/protocol/license_7e.h"
//#include "modules/canbus/vehicle/kia_niro/protocol/misc_69.h"
#include "modules/canbus/vehicle/kia_niro/protocol/steering_64.h"
#include "modules/canbus/vehicle/kia_niro/protocol/steering_65.h"
#include "modules/canbus/vehicle/kia_niro/protocol/surround_73.h"
#include "modules/canbus/vehicle/kia_niro/protocol/throttle_62.h"
#include "modules/canbus/vehicle/kia_niro/protocol/throttle_63.h"
#include "modules/canbus/vehicle/kia_niro/protocol/throttleinfo_75.h"
#include "modules/canbus/vehicle/kia_niro/protocol/tirepressure_71.h"
#include "modules/canbus/vehicle/kia_niro/protocol/turnsignal_68.h"
#include "modules/canbus/vehicle/kia_niro/protocol/version_7f.h"
#include "modules/canbus/vehicle/kia_niro/protocol/wheelspeed_6a.h"

namespace apollo {
namespace canbus {
namespace kia_niro {

Kia_niroMessageManager::Kia_niroMessageManager() {
  // TODO(Authors): verify which one is recv/sent

//send
  AddSendProtocolData<Brake60, true>();      //send
  AddSendProtocolData<Throttle62, true>();   //send
  AddSendProtocolData<Steering64, true>();   //send
  AddSendProtocolData<Gear66, true>();       //send
  AddSendProtocolData<Turnsignal68, true>(); //send

//recieve
  AddRecvProtocolData<Brake61, true>();     //recieve
  AddRecvProtocolData<Throttle63, true>();  //recieve
  AddRecvProtocolData<Steering65, true>();  //recieve
  AddRecvProtocolData<Gear67, true>();      //recieve
 // AddRecvProtocolData<Misc69, true>();
  AddRecvProtocolData<Wheelspeed6a, true>();  //recieve
  AddRecvProtocolData<Accel6b, true>();       //recieve
  AddRecvProtocolData<Gyro6c, true>();        //recieve
  AddRecvProtocolData<Gps6d, true>();         //recieve
  AddRecvProtocolData<Gps6e, true>();         //recieve
  AddRecvProtocolData<Gps6f, true>();         //recieve
  AddRecvProtocolData<Tirepressure71, true>();
  AddRecvProtocolData<Fuellevel72, true>();
  AddRecvProtocolData<Surround73, true>();
  AddRecvProtocolData<Brakeinfo74, true>();
  AddRecvProtocolData<Throttleinfo75, true>();
  AddRecvProtocolData<Version7f, true>();
  AddRecvProtocolData<License7e, true>();
}

Kia_niroMessageManager::~Kia_niroMessageManager() {}

}  // namespace Kia_niro
}  // namespace canbus
}  // namespace apollo
