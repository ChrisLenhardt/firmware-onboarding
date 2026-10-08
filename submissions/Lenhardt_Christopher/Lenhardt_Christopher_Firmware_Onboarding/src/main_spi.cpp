#include <Arduino.h>

#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

namespace
{
    bool sensor_ready = false;
    bool led_is_on = false;
    unsigned long last_led_toggle = 0;
}

void setup()
{
    Serial.begin(BMEConstants::kMonitorSpeed);

    auto &sensor = BMESPIInterfaceInstance::instance();
    SPI.begin();
    sensor_ready = sensor.init_sensor(BMEConstants::kBmeSpiChipSelectPin, &SPI);

    auto &led = LedControllerInstance::instance();
    led.deactivate_led();

    if (!sensor_ready)
    {
        Serial.println("BME280 SPI initialization failed.");
    }
}

void loop()
{
    if (!sensor_ready)
    {
        return;
    }

    auto &sensor = BMESPIInterfaceInstance::instance();
    auto &led = LedControllerInstance::instance();

    const float temperature = sensor.get_sensor_temp();
    Serial.println(temperature);
    led.update_led_period(temperature);

    const unsigned long current_time = millis();
    const unsigned long led_period =
        static_cast<unsigned long>(led.get_led_period());

    if (current_time - last_led_toggle >= led_period)
    {
        last_led_toggle = current_time;
        led_is_on = !led_is_on;

        if (led_is_on)
        {
            led.activate_led();
        }
        else
        {
            led.deactivate_led();
        }
    }
}