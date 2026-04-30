#pragma once

#include <string>
#include <vector>

#include "Forward.hpp"
#include "Node.hpp"
#include "Rail.hpp"

static const double G_gravity = 9.81;

std::vector<std::string> split(std::string p_line, const std::string& delimiter);
Rail* getRailByTraject(std::vector<Rail*> p_rails, std::string p_dep, std::string p_arr);
Node* getNodeByName(std::vector<Node*> p_nodes, std::string p_name);
