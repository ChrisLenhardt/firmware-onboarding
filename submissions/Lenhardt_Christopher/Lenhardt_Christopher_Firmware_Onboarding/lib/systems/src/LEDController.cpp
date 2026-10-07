#include "LEDController.h"

void LedController::activate_led()
{
    pinMode(BMEConstants::kLedPin, OUTPUT);
    digitalWrite(BMEConstants::kLedPin, HIGH);
}

void LedController::deactivate_led()
{
    pinMode(BMEConstants::kLedPin, OUTPUT);
    digitalWrite(BMEConstants::kLedPin, LOW);
}

void LedController::update_led_period(float temperature)
{
    if (temperature <= BMEConstants::kMinTemperatureC)
    {
        _curr_led_period = BMEConstants::kSlowBlinkPeriodMs;
        return;
    }

    if (temperature >= BMEConstants::kMaxTemperatureC)
    {
        _curr_led_period = BMEConstants::kFastBlinkPeriodMs;
        return;
    }

    const float temperature_fraction =
        (temperature - BMEConstants::kMinTemperatureC) / BMEConstants::kTempRange;

    _curr_led_period =
        BMEConstants::kSlowBlinkPeriodMs + temperature_fraction * BMEConstants::kPeriodRange;
}

float LedController::get_led_period()
{
    return _curr_led_period;
}