/*
 * Copyright (c) 2021 Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 * 
 */

#ifndef _PICO_ST7789_H_
#define _PICO_ST7789_H_

#include "platform/spi.h"

typedef struct st7789_config {
    mcu_spi_bus_config_t spi_cfg;
    int8_t gpio_cs;
    uint8_t gpio_dc;
    uint8_t gpio_rst;
    uint8_t gpio_bl;
} st7789_config_t;

void st7789_init(const struct st7789_config* config, uint16_t width, uint16_t height);
void st7789_write(const void* data, size_t len);
void st7789_put(uint16_t pixel);
void st7789_fill(uint16_t pixel);
void st7789_set_cursor(uint16_t x, uint16_t y);
void st7789_vertical_scroll(uint16_t row);

#endif
