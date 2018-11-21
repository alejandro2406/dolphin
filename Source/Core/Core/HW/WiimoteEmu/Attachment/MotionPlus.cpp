// Copyright 2018 Dolphin Emulator Project
// Licensed under GPLv2+
// Refer to the license.txt file included.

#pragma once

#include "Core/HW/WiimoteEmu/Attachment/MotionPlus.h"

#include <array>

#include "Common/Common.h"
#include "Common/CommonTypes.h"
#include "Core/HW/WiimoteEmu/WiimoteEmu.h"

namespace WiimoteEmu
{
constexpr std::array<u8, 6> motion_plus_id{{0x00, 0x00, 0xa4, 0x20, 0x04, 0x05}};

MotionPlus::MotionPlus(ExtensionReg& reg)
{
 // m_id = motion_plus_id;
}

void MotionPlus::GetState(u8* const data, bool active_extension)
{
  wm_motionplus_data motionplus_data = {};
  motionplus_data.yaw1 = 0;
  motionplus_data.yaw2 = 0;
  motionplus_data.yaw_slow = 1;

  motionplus_data.pitch1 = 0;
  motionplus_data.pitch2 = 0;
  motionplus_data.pitch_slow = 1;

  motionplus_data.roll1 = 0;
  motionplus_data.roll2 = 0;
  motionplus_data.roll_slow = 1;

  motionplus_data.extension_connected = active_extension;
  motionplus_data.is_mp_data = 1;
  motionplus_data.zero = 0;

  std::memcpy(data, &motionplus_data, sizeof(wm_motionplus_data));
}
}
