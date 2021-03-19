#pragma once
#include "Node.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using node_queue = std::priority_queue <Node, std::vector<Node>, LowestPrioriry>;

bool* make_bit_array(int& bit_counter, int fsize, uch* text, std::map <uch, Code>& map);
void write_to_file(std::vector <Node>& queue_copy, bool* bit_array, int bit_counter);

