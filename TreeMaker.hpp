#pragma once
#include "Node.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using node_queue = std::priority_queue <Node, std::vector<Node>, LowestPrioriry>;

node_queue make_priority_queue(std::vector<int>& frequency);
std::vector <Node> copy_queue(node_queue& queue);
Node make_heritages(node_queue& queue, std::list <Node>& all_nodes);
std::map <uch, Code> make_map_char_code(std::list <Node>& all_nodes);