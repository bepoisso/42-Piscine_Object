/**
 * @file Forward.hpp
 * @brief Forward declarations - Reduce include dependencies
 * 
 * @details
 * Provides forward declarations for core types to avoid circular includes
 * and reduce compilation time.
 * 
 * @note
 * principles Dependency reduction
 */

#pragma once

#include "Type.hpp"

class Simulation;
class Parsing;
class Clock;
class Train;
class Rail;
class Node;
class Factory;
class Movement;
class Graph;
class Pathfinder;
class Time;
class SimulationEngine;
class TrainManager;
class AEvent;
class EventManager;
class CityDelayedEvent;
class RailBlockedEvent;
class RailLimitationEvent;
