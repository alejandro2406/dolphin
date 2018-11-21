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

MotionPlus::MotionPlus(ExtensionReg& reg) : Attachment(_trans("Motion Plus"), reg)
{
  m_id = motion_plus_id;
}

void MotionPlus::GetState(u8* const data)
{
  wm_motionplus_data motionplus_data = {};

  std::memcpy(data, &motionplus_data, sizeof(wm_motionplus_data));
}
}
