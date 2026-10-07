#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"


class BMESPIInterface
{
public:

    BMESPIInterface() = default;

    bool init_sensor(int8_t cspin, SPIClass *theSPI = &SPI);

    float get_sensor_temp();

private:

    Adafruit_BME280 _sensor;
    float _last_recvd_temp{0.0F};
    bool _initialized = false;

};
using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;