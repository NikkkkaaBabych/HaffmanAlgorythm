#include "Node.hpp"

using uch = unsigned char;


	Node::Node(uch chr, int count) {
		text = new uch[1];
		text[0] = chr;
		text_size = 1;
		frequency = count;
	}
	Node::Node(Node* ch0, Node* ch1) {
		text_size = ch0->text_size + ch1->text_size;
		text = new uch[text_size];
		copy_text(ch0, 0);
		copy_text(ch1, ch0->text_size);
		frequency = ch0->frequency + ch1->frequency;
		child0 = ch0;
		child1 = ch1;
		ch0->print_char();
		std::cout << " + ";
		ch1->print_char();
		std::cout << " = ";
		print_char();
		std::cout << std::endl;
	}
	Node::Node(const Node& other) {
		text_size = other.text_size;
		text = new uch[text_size];
		copy_text(&other, 0);
		frequency = other.frequency;
		child0 = other.child0;
		child1 = other.child1;
        uch bin_code{ 0 };
        uch code_size{ 0 };
	}
	void Node::copy_text(const Node* child, uch k) {
		for (uch i = 0; i < child->text_size; i++) {
			text[k + i] = child->text[i];
		}
	}
	Node::~Node() { 
		delete[]text;
		text = nullptr;
	}

	Node& Node::operator = (const Node& other) {
		text_size = other.text_size;
		delete[]text;
		text = new uch[text_size];
		copy_text(&other, 0);
		frequency = other.frequency;
		child0 = other.child0;
		child1 = other.child1;
		return *this;
	}
	uch Node::operator[](uch i) const {
		return text[i];
	}
	uch Node::get_size() const {
		return text_size;
	}
	int Node::get_frequency() const {
		return frequency;
	}
	uch Node::get_char0() const {
		return text[0];
	}
	const Node* Node::get_child0() {
		return child0;
	}
	const Node* Node::get_child1() {
		return child1;
	}
	void Node::print_char() const {
		for (uch i = 0; i < text_size; i++) {
			std::cout << text[i];
		}
	}

    void Node::initial_coding() {
		std::cout << "\n\nCoding...\n \n ";
        if (child0 != nullptr) child0->give_codes(0, 0, 0);
        if (child1 != nullptr) child1->give_codes(0, 0, 1);
    }
    void Node::give_codes(size_t father_code, uch father_code_size, uch last_sign) {
        bin_code = father_code;
        code_size = father_code_size;
        if (bin_code) bin_code <<= 1; //make spase for new bit at the end, making it defaulf "0"
        bin_code += last_sign; //last_sign = 0 or 1
        code_size++;
        if (child0 != nullptr) child0->give_codes(bin_code, code_size, 0);
        if (child1 != nullptr) child1->give_codes(bin_code, code_size, 1);
    }
	size_t Node::get_code() const {
        return bin_code;
    }
    uch Node::get_code_size() const {
        return code_size;
    }
    //void Node::print_tree() {
    //    print_char();
    //    std::cout << "\n";
    //    if (child0 != nullptr) child0-> print_tree();
    //    if (child1 != nullptr) child1->print_tree();
    //}
	std::ostream& operator<<(std::ostream& os, const Node& nd) {
		os << "[";
		for (uch i = 0; i < nd.get_size(); i++) {
			os << nd[i];
		}
		os << "] = " << nd.get_frequency() << ", ";
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const Code& nd) {
		auto b = std::bitset<32>(nd.bin_code);
		for (uch i = nd.code_size; i > 0; --i) {
			os << b[i - 1];
		}
		return os;
	}