#pragma once

#include <etl/singleton.h>
#include "BMEConstants.h"

class LedController {
    public:
        void activate_led();
        void deactivate_led();
        void update_led_period(float temperature);
        float get_led_period();

    private:
        float _curr_led_period = BMEConstants::kSlowBlinkPeriodMs;


};
using LedControllerInstance = etl::singleton<LedController>;
