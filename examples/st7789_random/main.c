/*
 * Copyright (c) 2021 Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 * 
 */

#include <stdlib.h>
#include <pico/stdlib.h>

#include "display/st7789.h"

// spi configuration
const mcu_spi_bus_config_t spi_config = {
    PICO_DEFAULT_SPI_SCK_PIN,
    PICO_DEFAULT_SPI_TX_PIN,
    PICO_DEFAULT_SPI_RX_PIN,
    0,
    125 * 1000 * 1000
};

// lcd configuration
const st7789_config_t lcd_config = {
    .spi_cfg = spi_config,
    .gpio_cs  = PICO_DEFAULT_SPI_CSN_PIN,
    .gpio_dc  = 20,
    .gpio_rst = 21,
    .gpio_bl  = 22,
};

const int LCD_WIDTH = 240;
const int LCD_HEIGHT = 320;

int main()
{
    // initialize the lcd
    st7789_init(&lcd_config, LCD_WIDTH, LCD_HEIGHT);

    // make screen black
    st7789_fill(0x0000);

    while (1) {
        // create a random x, y, and color value
        int rand_x = rand() % LCD_WIDTH;
        int rand_y = rand() % LCD_HEIGHT;
        uint16_t rand_color = rand() % 0xffff;
        
        // move the cursor to the random x and y position
        st7789_set_cursor(rand_x, rand_y);

        // put the random color as the pixel value
        st7789_put(rand_color);
    }
}
