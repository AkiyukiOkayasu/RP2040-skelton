#include "SEGGER_RTT.h"
#include "constants.hpp"
#include "hardware/gpio.h"
// #include "hardware/i2c.h"
// #include "hardware/pwm.h"
#include "pico/binary_info.h"
#include "pico/stdlib.h"
// #include "pico/time.h"
// #include "pum.hpp"
// #include "tusb.h"

#include <cstdint>
#include <cstdio>

int main()
{
    // Project discripsion.
    bi_decl (bi_program_description ("This is a skelton project for RP2040."));
    bi_decl (bi_1pin_with_name (pin::led, "Pico on-board LED"));

    // Init stdio
    stdio_init_all();

    // Init GPIO
    gpio_init (pin::led);
    gpio_set_dir (pin::led, GPIO_OUT);

    while (1)
    {
        std::printf ("test\n");                                     //USB-Serial console output
        SEGGER_RTT_WriteString (0, "Hello World from SEGGER!\r\n"); //SEGGER RTT console output

        //LED blink
        gpio_put (pin::led, 1);
        sleep_ms (250);
        gpio_put (pin::led, 0);
        sleep_ms (250);
    }
}