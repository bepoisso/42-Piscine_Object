/**
 * @file Config.hpp
 * @brief Configuration header - Global simulation configuration
 * 
 * @details
 * Centralizes compile-time configuration macros used across the simulation,
 * such as `DELTA_TIME`, `START_TIME`, and `EVENTS`.
 * 
 * @note
 * principles SRP, Encapsulation
 */

#ifndef _CONFIG_HPP_
# define _CONFIG_HPP_

# define DELTA_TIME 1			// Set the delta time of the simulation (step) in secondes.
# define START_TIME 28800		//Set the start time of the simulation (hours) in seconde. (28800 = 08h00)
# define EVENTS true			// Set to true to enable random events, false to disable.

#endif
