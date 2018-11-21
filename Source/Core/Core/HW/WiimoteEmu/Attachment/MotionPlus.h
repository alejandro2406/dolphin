// Copyright 2018 Dolphin Emulator Project
// Licensed under GPLv2+
// Refer to the license.txt file included.

#pragma once

#include "Core/HW/WiimoteEmu/Attachment/Attachment.h"

namespace WiimoteEmu
{

class MotionPlus
{
public:
  explicit MotionPlus(ExtensionReg& reg);

  void GetState(u8* const data, WiimoteEmu::Attachment* attachment, bool active_extension);

  enum
  {
    NO_PASSTHROUGH = 4,
    NUNCHUK_PASSTHROUGH = 5,
    CLASSIC_PASSTHROUGH = 7,
  };
  u8 mode;

private:
  bool m_report_ext_data;
};
}
