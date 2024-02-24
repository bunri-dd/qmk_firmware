/*
Copyright 2020 Pierre Chevalier <pierrechevalier83@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
// Set the mouse settings to a comfortable speed/accuracy trade-off,
// assuming a screen refresh rate of 60 Htz or higher
// The default is 50. This makes the mouse ~3 times faster and more accurate
#define EE_HANDS
// handedness by EEPROM


// Pick good defaults for enabling homerow modifiers
#define TAPPING_TERM 160
#define PERMISSIVE_HOLD
#define QUICK_TAP_TERM 0

// Underglow configuration
#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_EFFECT_SNAKE
#    define RGBLIGHT_EFFECT_KNIGHT
#    define RGBLIGHT_EFFECT_CHRISTMAS
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    define RGBLIGHT_EFFECT_RGB_TEST
#    define RGBLIGHT_EFFECT_ALTERNATING
#    define RGBLIGHT_EFFECT_TWINKLE
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 8
#endif

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED D5 // Specify an optional status LED by GPIO number which blinks when entering the bootloader


#define MOUSEKEY_DELAY 	            0 //10 	Delay between pressing a movement key and cursor movement
#define MOUSEKEY_INTERVAL       	16 //20 	Time between cursor movements in milliseconds
// #define MOUSEKEY_MOVE_DELTA        	//8 	Step size
#define MOUSEKEY_MAX_SPEED 	        6 //10 	Maximum cursor speed at which acceleration stops
#define MOUSEKEY_TIME_TO_MAX 	    64 //30 	Time until maximum cursor speed is reached
#define MOUSEKEY_WHEEL_DELAY 	    10 //10 	Delay between pressing a wheel key and wheel movement
#define MOUSEKEY_WHEEL_INTERVAL 	100 //80 	Time between wheel movements
// #define MOUSEKEY_WHEEL_DELTA 	    //1 	Wheel movement step size
// #define MOUSEKEY_WHEEL_MAX_SPEED 	//8 	Maximum number of scroll steps per scroll action
#define MOUSEKEY_WHEEL_TIME_TO_MAX 	100 //40 	Time until maximum scroll speed is reached

