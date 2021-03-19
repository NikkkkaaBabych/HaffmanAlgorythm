#include "Node.hpp"
#include "CodeWriter.hpp"
using node_queue = std::priority_queue <Node, std::vector<Node>, LowestPrioriry>;

bool* make_bit_array(int& bit_counter, int fsize, uch* text, std::map <uch, Code>& map) {
    std::cout << "\n\nMaking bit array...\n \n ";
    bool* bit_array = new bool[8 * fsize];
    for (int l = 0; l < fsize; ++l) {
        uch letter = text[l];
        auto b = std::bitset<32>(map[letter].bin_code);
        for (uch i = map[letter].code_size; i > 0; --i) {
            bit_array[bit_counter] = b[i - 1];
            ++bit_counter;
        }
    }
    for (int i = 0; i < bit_counter; ++i) {
        std::cout << bit_array[i];
    }
    return bit_array;
}

void write_to_file(std::vector <Node>& queue_copy, bool* bit_array, int bit_counter) {
    std::cout << "\n\nWriting to file...\n \n ";

    std::string filename2 = "output.txt";
    //std::cin >> filename2;
    std::ofstream ofs(filename2, std::ofstream::binary);
    if (!ofs) {
        std::cout << "error whis file output";
    }
    std::cout << queue_copy.size();
    ofs << queue_copy.size();
    for (size_t i = 0; i < queue_copy.size(); ++i) {
        std::cout << queue_copy[i].get_char0() << queue_copy[i].get_frequency()<<" ";
        ofs << queue_copy[i].get_char0() << queue_copy[i].get_frequency() << " ";
    }
    for (int i = 0; i < bit_counter / 8; ++i) {
        auto b = std::bitset<8>();
        for (int j = 0; j < 8; ++j) {
            b[j] = bit_array[i * 8 + j];
        }
        std::cout << (char)b.to_ulong();
        ofs << (char)b.to_ulong();
    }
    std::cout << "\n\n";
}
