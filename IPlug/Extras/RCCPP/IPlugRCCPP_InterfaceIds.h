#pragma once

#ifndef INTERFACEIDS_INCLUDED
#define INTERFACEIDS_INCLUDED

#include "RuntimeObjectSystem/IObject.h"

enum InterfaceIDEnumIPlug
{
  IID_IUPDATEABLE = IID_ENDInterfaceID,
  IID_IPLUGEFFECT,

  IID_ENDInterfaceIDEnumIPlug
};

namespace iplug
{
  class IPlugAPP;
}

struct SystemTable
{
  iplug::IPlugAPP* pPlug;
  void* pAppHost; // for InstanceInfo
};

#endif //INTERFACEIDS_INCLUDED
