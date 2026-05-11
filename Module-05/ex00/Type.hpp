/**
 * @file Type.hpp
 * @brief Type definitions - Simulation enums
 * 
 * @details
 * Defines enums for train states and event types used across the module.
 * 
 * @note
 * principles Readability, Type safety
 */

#pragma once

enum TrainState {
	ACCELERATING,
	MAINTAINING,
	BRAKING,
	STOPPED
};

enum EventType {
	CITY_DELAYED,
	RAIL_LIMITATION,
	RAIL_BLOCKED
};
