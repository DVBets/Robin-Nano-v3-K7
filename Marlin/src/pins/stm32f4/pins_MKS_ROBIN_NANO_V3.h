/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

#define ALLOW_STM32DUINO
#include "env_validate.h"

#if HOTENDS > 2 || E_STEPPERS > 2
  #error "MKS Robin Nano V3 supports up to 2 hotends / E-steppers."
#elif HAS_FSMC_TFT
  #error "MKS Robin Nano V3 doesn't support FSMC-based TFT displays."
#endif

#define BOARD_INFO_NAME "MKS Robin Nano V3"

#ifndef X_CS_PIN
  #define X_CS_PIN                          PD5
#endif

#ifndef Y_CS_PIN
  #define Y_CS_PIN                          PD7
#endif

#ifndef Z_CS_PIN
  #define Z_CS_PIN                          PD4
#endif

#ifndef E0_CS_PIN
  #define E0_CS_PIN                         PD9
#endif

#ifndef E1_CS_PIN
  #define E1_CS_PIN                         PD8
#endif

//
// Software SPI pins for TMC2130 stepper drivers
// This board only supports SW SPI for stepper drivers
//
#if HAS_TMC_SPI
  #define TMC_USE_SW_SPI
#endif
#if ENABLED(TMC_USE_SW_SPI)
  #if !defined(TMC_SW_MOSI) || TMC_SW_MOSI == -1
    #define TMC_SW_MOSI                     PD14
  #endif
  #if !defined(TMC_SW_MISO) || TMC_SW_MISO == -1
    #define TMC_SW_MISO                     PD1
  #endif
  #if !defined(TMC_SW_SCK) || TMC_SW_SCK == -1
    #define TMC_SW_SCK                      PD0
  #endif
#endif

#include "pins_MKS_ROBIN_NANO_V3_common.h"

//
// === Easythreed K7 Custom Pins ===
//

// ---- HOMING BUTTON ----
#define BUTTON_HOME_PIN PE7
#define BUTTON_HOME_STATE LOW

// ---- MAIN FUNCTION BUTTON ----
#define BUTTON_MAIN_PIN PE6
#define BUTTON_MAIN_STATE LOW

// ---- MAIN LED (green) ----
#define MAIN_LED_PIN PB2
#define MAIN_LED_INVERTED false

// ---- LEVELLING BUTTONS ----
#define BUTTON4_PIN PA15   // yellow
#define BUTTON5_PIN PD2    // white
#define BUTTON6_PIN PC8    // red
#define BUTTON7_PIN PC4    // black

#define BUTTON4_HIT_STATE LOW
#define BUTTON5_HIT_STATE LOW
#define BUTTON6_HIT_STATE LOW
#define BUTTON7_HIT_STATE LOW

// Levelling actions
#define BUTTON4_GCODE "G0 Z5\nG0 X0 Y0\nG0 Z0"
#define BUTTON5_GCODE "G0 Z5\nG0 X100 Y0\nG0 Z0"
#define BUTTON6_GCODE "G0 Z5\nG0 X100 Y100\nG0 Z0"
#define BUTTON7_GCODE "G0 Z5\nG0 X0 Y100\nG0 Z0"

#define BUTTON4_DESC "Levelling button 1"
#define BUTTON5_DESC "Levelling button 2"
#define BUTTON6_DESC "Levelling button 3"
#define BUTTON7_DESC "Levelling button 4"


// ---- FEED / NORMAL / RETRACT SWITCH ----
#define FEED_SWITCH_PIN     PA6
#define NORMAL_SWITCH_PIN   PA7
#define RETRACT_SWITCH_PIN  PE10
#define RESERVE_SWITCH_PIN  PE12   // spare or diagnostic

// Enable pullups
SET_INPUT_PULLUP(FEED_SWITCH_PIN);
SET_INPUT_PULLUP(NORMAL_SWITCH_PIN);
SET_INPUT_PULLUP(RETRACT_SWITCH_PIN);
SET_INPUT_PULLUP(RESERVE_SWITCH_PIN);

//
// Placeholder handlers – you’ll implement logic later
//
inline void handle_feed()    {}
inline void handle_normal()  {}
inline void handle_retract() {}

inline void poll_feed_switch() {
  if (!READ(FEED_SWITCH_PIN))      handle_feed();
  else if (!READ(NORMAL_SWITCH_PIN))  handle_normal();
  else if (!READ(RETRACT_SWITCH_PIN)) handle_retract();
}