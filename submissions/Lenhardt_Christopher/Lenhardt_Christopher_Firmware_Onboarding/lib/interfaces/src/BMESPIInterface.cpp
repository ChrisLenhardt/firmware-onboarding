#include "BMESPIInterface.h"

bool BMESPIInterface::init_sensor(int8_t cspin, SPIClass *theSPI){
    _sensor = Adafruit_BME280(cspin, theSPI);
    _initialized = _sensor.begin();
    return _initialized;
}

float BMESPIInterface::get_sensor_temp() {
    if (_initialized) {
        _last_recvd_temp = _sensor.readTemperature();
    }
    return _last_recvd_temp;
}