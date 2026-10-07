#include "BMEI2CInterface.h"

bool BMEI2CInterface::init_sensor(uint8_t addr, TwoWire *theWire) {
    _sensor = Adafruit_BME280();
    _initialized = _sensor.begin(addr, theWire);
    return _initialized;
}

float BMEI2CInterface::get_sensor_temp() {
    if (_initialized) {
        _last_recvd_temp = _sensor.readTemperature();
    }
    return _last_recvd_temp;
}