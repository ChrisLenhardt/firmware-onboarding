#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"


class BMEI2CInterface
{
public:

    BMEI2CInterface() = default;

    bool init_sensor(uint8_t addr = BME280_ADDRESS, TwoWire *theWire = &Wire);

    float get_sensor_temp();


private:
    
    Adafruit_BME280 _sensor;
    float _last_recvd_temp{0.0F};
    bool _initialized = false;

};
using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;