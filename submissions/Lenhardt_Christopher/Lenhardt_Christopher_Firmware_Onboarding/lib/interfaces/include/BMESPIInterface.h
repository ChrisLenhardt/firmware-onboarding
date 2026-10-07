#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"


class BMESPInterface
{
public:

    BMESPInterface() = default;

    // Code here!

private:

   // Code here!

};
using BMESPInterfaceInstance = etl::singleton<BMESPInterface>;