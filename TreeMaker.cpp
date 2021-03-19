#include "Node.hpp"
#include "TreeMaker.hpp"
using node_queue = std::priority_queue <Node, std::vector<Node>, LowestPrioriry>;

node_queue make_priority_queue(std::vector<int>& frequency) {
    std::cout << "\n\nMaking queue...\n \n ";
    node_queue queue;
    for (unsigned int i = 0; i <= frequency.size(); ++i) {
        uch uni = static_cast<unsigned char>(i);
        int count = frequency[uni];
        if (count != 0) {
            queue.emplace(uni, count);
        }
    }

    return queue;
}
std::vector <Node> copy_queue(node_queue& queue) {
    std::vector <Node> queue_copy;
    node_queue queue2 = queue;
    while (!queue2.empty()) {
        std::cout << queue2.top();
        queue_copy.push_back(queue2.top());
        queue2.pop();
    }
    return queue_copy;
}
Node make_heritages(node_queue& queue, std::list <Node>& all_nodes) {
    std::cout << "\n\nMaking heritages...\n \n ";
    while (!queue.empty()) {
        all_nodes.emplace_back(queue.top());
        queue.pop();
        if (queue.empty()) {
            return all_nodes.back();
        }
        else {
            all_nodes.emplace_back(queue.top());
            queue.pop();

            std::list<Node>::iterator it = all_nodes.end();
            --it;
            Node* ch1 = &(*it);
            --it;
            Node* ch0 = &(*it);
            queue.emplace(ch0, ch1);
        }
    }
    return all_nodes.back();
}

std::map <uch, Code> make_map_char_code(std::list <Node>& all_nodes) {
    std::map <uch, Code> map;
    for (std::list<Node>::iterator it = all_nodes.begin(); it != all_nodes.end(); ++it) {
        if ((*it).get_size() == 1) {
            Code code{ (*it).get_code(), (*it).get_code_size() };
            map.emplace(std::make_pair((*it).get_char0(), code));
        }
    }
    for (const auto& m : map) {
        std::cout << m.first << " = " << m.second << "; ";
    }
    return map;
}