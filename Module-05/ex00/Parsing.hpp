/**
 * @file Parsing.hpp
 * @brief Parsing class - Class for parse inputs files
 * 
 * @details
 * This class reads, verifies and extracts data from configuration inputs files
 * containing rail network and train information. It parses these files,
 * validates the data according to specific rules and formats, and transmits
 * the validated information to the simulation engine for processing and execution.
 * 
 * @note
 * Principles used:
 * - Separation of concerns: the class is limited to reading and validating
 *		configuration files (rail network and train compositions).
 * - Encapsulation: internal data (_nodes, _rails, _trains) are private and
 *		accessed via const accessors to prevent external modification.
 * - Defensive validation (fail-fast): strict checks of formats and values
 *		to detect and report errors as early as possible.
 * - Resource management: file access via streams and cleanup in the
 *		destructor to avoid leaks (RAII-inspired behavior).
 * - Simplicity and robustness: explicit format rules and detailed checks
 *		to prevent undefined behavior during the simulation.
 */

#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include "Utils.hpp"

#include "Simulation.hpp"


class Parsing {
private:
	const std::string _railNetworkPath;
	const std::string _trainComposePath;

	std::ifstream* _railnetworkFile;
	std::ifstream* _trainComposeFile;

	std::vector<std::string> _nodes;
	std::vector<std::string> _rails;
	std::vector<std::string> _trains;

	void railNetworkChecker();
	void railChecker(std::string p_line);
	void nodeChecker(std::string p_line);
	void checkDoubleRail(std::string trajectID);
	bool isEmptyNode(std::string p_node);

	void trainComposeChecker();
	void trainChecker(std::string p_line);
	void checkDoubleTrain(std::string p_name);

	bool isemptyFile(std::ifstream* p_file);
	bool isFloat(std::string p_arg);
	bool isInt(std::string p_arg);
	bool isHours(std::string p_arg);
	bool isANode(std::string p_name);
public:
	Parsing(const std::string p_railNetworkpath, const std::string p_trainComposePath);
	~Parsing();

	void checkInputError();
	std::vector<std::string> 	getNodes() const { return _nodes; }
	std::vector<std::string> 	getRails() const { return _rails; }
	std::vector<std::string> 	getTrains() const { return _trains; }

	// TODO: delete pour la mise en prod
	void D_printList(std::vector<std::string> p_list) { std::cout << "\033[32m___DEBUG PRINT LIST___" << std::endl; for (std::vector<std::string>::iterator it = p_list.begin(); it != p_list.end(); ++it) std::cout << *it << std::endl; std::cout << "___DEBUG PRINT END___\033[0m" << std::endl; }
};

// TODO PARSING:
/* Hash case parsing
?Fichier
	- Pas le bon Path
	- C'est pas un fichier mais un dossier
	- Fichier sans les droit

?Rail Network
	- Fichier vide
	- Fichier avec nimporte quoi
	- Autre choses que Node ou Rail

	?Node
		- Pas un nom Alphabetique
		- Pas de nom
		- pas le bon nombre de parametre	(1)
		- Double node
		- Autoriser seullement les nom commencent par City et Rail pour identification
		- Verifier que toutes les nodes soit link au reaseau
	
	?Rail
		- Pas le bon nombre de parametres	(4)
		- La node departure existe pas
		- La node arrival existe pas
		?Verifier que le trajet n'existe pas deja ?
		- Pas le bon formas pour la lenght			(double)
		- Pas le bon formas pour la Speed Limitation	(double)
		*Valeur absudre pour la lenght				(0.0 - 99999.0)
		*Valeur absurde pour la Speed Limitation		(0.0 - 99999.0)

?Train Composition
	- Fichier Vide
	- Fichier avec nimporte quoi
	
	?Train
		- Pas le bon nombre de parametres				(9)
		- Le nom n'est pas alphabetique
		- Pas le bon format pour le weight			(int)
		- Pas le bon format pour la friction			(double)
		- Pas le bon format pour l'acceleration		(double)
		- Pas le bon format pour la brake force		(double)
		- La node departure n'existe pas
		- La node Arrival n'existe pas
		- Pas le bon format pour le departure time	(Heurs donc (0-23h0-59))
		- Pas le bon format pour le stop time			(Heurs donc (0-23h0-59))
		*Valeure absurde pour le weight				(0 - 99999)
		*Valeure absurde pour la friction			(0.0 - 99999.0)
		*Valeure absurde pour l'acceleration			(0.0 - 99999.0)
		*Valeure absurde pour la brake force			(0.0 - 99999.0)
*/

