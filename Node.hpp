#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <bitset>

struct LowestPrioriry;

using uch = unsigned char;

struct Node {
	Node() = default;
	Node(uch chr, int count);
	Node(Node* ch0, Node* ch1);
	Node(const Node& other);
	~Node();
	void copy_text(const Node* child, uch k);
	Node& operator = (const Node& other);
	uch operator[](uch i) const;
	uch get_size() const;
	int get_frequency() const;
	uch get_char0() const;
	const Node* get_child0();
	const Node* get_child1();
	void print_char() const;
    void initial_coding();
    void give_codes(size_t father_code, uch father_code_size, uch last_sign);
	size_t get_code() const;
    uch get_code_size() const;
	//void print_tree();

private:
	uch* text{ nullptr };
	uch text_size{ 0 };
	int frequency{ 0 };
	Node* child0{ nullptr };
	Node* child1{ nullptr };
	size_t bin_code{ 0 };
	uch code_size{ 0 };
};
struct LowestPrioriry {
	bool operator()(const Node& left, const Node& right) {
		return left.get_frequency() > right.get_frequency();
	}
};

struct Code {
	size_t bin_code{ 0 };
	uch code_size{ 0 };
};

std::ostream& operator<<(std::ostream& os, const Node& nd);
std::ostream& operator<<(std::ostream& os, const Code& nd);

