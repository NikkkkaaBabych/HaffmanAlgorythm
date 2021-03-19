#include "Node.hpp"
#include "CodeWriter.hpp"
#include "TreeMaker.hpp"

using node_queue = std::priority_queue <Node, std::vector<Node>, LowestPrioriry>;
using uch = unsigned char;

std::ifstream::pos_type get_size(const std::string& fn) {
    std::ifstream ifs(fn, std::ifstream::ate);
    return ifs.tellg();
}

int main()
{
    std::cout << "Reading file...\n \n ";
    std::string filename = "input.txt";
    std::cin >> filename;
    int fsize = get_size(filename);
    if (fsize < 0) {
        std::cout << "error whis file input";
        return 1;
    }
    std::ifstream ifs(filename, std::ifstream::binary);
    if (!ifs) {
        std::cout << "error whis file input";
        return 2;
    }    
    std::vector<int> frequency(0x100, 0);
    uch* text = new uch[fsize];
    uch max_unch{ 0 };
    for (int i = 0; i < fsize; ++i) {
        char ch;
        ifs.read(&ch, 1);
        uch unch = static_cast<unsigned char>(ch);
        frequency[unch] += 1;
        std::cout << ch;
        text[i] = unch;
    }
    node_queue queue = make_priority_queue(frequency);
    std::vector <Node> queue_copy = copy_queue(queue);
    std::list <Node> all_nodes;
    Node root = make_heritages(queue, all_nodes);
    root.initial_coding();
    std::map <uch, Code> map = make_map_char_code(all_nodes);
    int bit_counter = 0;
    bool* bit_array = make_bit_array(bit_counter, fsize, text, map);
    write_to_file(queue_copy, bit_array, bit_counter);
    
    return 0;
}


