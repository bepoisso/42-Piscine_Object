/**
 * @file Forward.hpp
 * @brief Forward class - Fix circular dependencies
 * 
 * @details
* This file contains forward declarations for classes used throughout the module.
* Forward declarations allow multiple source files to reference classes without
* including their full definitions, reducing compilation dependencies and improving
* build times.
 * 
 * @note
 * Forward Declaration Principles:
 * - Reduces compilation dependencies between translation units
 * - Improves build times by avoiding unnecessary includes
 * - Allows circular dependencies to be resolved
 * - Enables loose coupling between classes
 * - Useful for pointer and reference declarations only
 */

#pragma once

#include "Type.hpp"
#include "Utils.hpp"

class Simulation;
class Parsing;
class Train;
class Rail;
class Node;
class Factory;
class Movement;
class Graph;
