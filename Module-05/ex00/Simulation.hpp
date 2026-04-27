/**
 * @file Simulation.hpp
 * @brief Simulation class - Main facade of the program
 * 
 * @details
 * This class serves as the facade pattern implementation, providing a unified
 * and simplified interface to the complex subsystems of the program.
 * It respects the SOLID principles, particularly the Single Responsibility Principle,
 * by delegating specific tasks to appropriate classes while maintaining a clean
 * and cohesive public API.
 * 
 * @note
 * principles SOLID
 * design_pattern Facade
 */

#pragma once

#include "Forward.hpp"

#include "Parsing.hpp"

class Simulation {
private:
	Parsing _parser;

public:
	Simulation(/* args */);
	~Simulation();

	// void paths(); //TODO: renvois ves _parser pour verifier les chemain d'acces et init les valleurs
};
