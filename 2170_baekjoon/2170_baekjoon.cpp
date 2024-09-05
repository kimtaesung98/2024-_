#include <iostream>

class Node {
public:
    int max;
    int min;
    Node* next;
    Node* prev;

    Node(int min, int max) : max(max), min(min), next(nullptr), prev(nullptr) {}
};

void delete_node(Node*& node) {
    Node* current = node->prev;
    if (current->next == node) {
        delete node;
        node = nullptr;
        return;
    }
    Node* node_next = node->next;
    Node* node_prev = node->prev;
    node_next->prev = node_prev;
    node_prev->next = node_next;
    delete node;
    node = nullptr;
}
Node* rotation(Node* node, int min, int max) {
    Node* current = node;
    Node* start = node;
    do {
        if (!(current->max < max || current->min > min)) {
            max = std::max(current->max, max);
            min = std::min(current->min, min);
            Node* to_delete = current;
            current = rotation(current,min,max);
            delete_node(to_delete);
        }
        else {
            current = current->next;
        }
    } while (current != start);

    Node* new_node = new Node(min, max);
    printf("make new_node : %d %d\n", min, max);
    if (node == nullptr) {
        new_node->next = new_node;
        new_node->prev = new_node;
        return new_node;
    }
    current = node->prev;
    new_node->next = node;
    new_node->prev = current;
    current->next = new_node;
    node->prev = new_node;
    return new_node;
}
Node* insert(Node* node, int min, int max) {
    if (node == nullptr) {
        Node* new_node = new Node(min, max);
        new_node->next = new_node;
        new_node->prev = new_node;
        return new_node;
    }
    return rotation(node, min, max);
}
void print(Node* node) {
    if (node == nullptr) return;

    Node* current = node;
    do {
        std::cout << current->min << " " << current->max << std::endl;
        current = current->next;
    } while (current != node);
}

int main() {
    int n, min, max;
    std::cin >> n;
    Node* node = nullptr;
    for (int i = 0; i < n; i++) {
        std::cin >> min >> max;
        node = insert(node, min, max);
    }
    print(node);
    return 0;
}