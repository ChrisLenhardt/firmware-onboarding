#pragma once
#include <Arduino.h>

namespace BMEConstants
{
    constexpr uint32_t kMonitorSpeed = 115200;

    constexpr uint8_t kLedPin = LED_BUILTIN;
    constexpr uint8_t kBmeSpiChipSelectPin = 10;
    constexpr uint8_t kTempSensorAddr = 0x76;

    constexpr float kMinTemperatureC = 26.0F;
    constexpr float kMaxTemperatureC = 28.0F;
    constexpr float kSlowBlinkPeriodMs = 1000.0F;
    constexpr float kFastBlinkPeriodMs = 100.0F;

    constexpr float kTempRange = kMaxTemperatureC - kMinTemperatureC;
    constexpr float kPeriodRange = kFastBlinkPeriodMs - kSlowBlinkPeriodMs;
}