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

  void GetState(u8* const data, bool active_extension);
};
}
