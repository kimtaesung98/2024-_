#include <iostream>

class Node {
public:
    int max;
    int min;
    Node* next;

    Node(int min, int max) : max(max), min(min), next(nullptr) {}
};

// 노드를 삭제하고 다음 노드를 반환
Node* delete_node(Node*& head, Node* prev, Node* current) {
    // 리스트 내에서 노드 삭제
    if (prev == nullptr) { // Head node is being deleted
        head = current->next; // Update head to the next node
    }
    else {
        prev->next = current->next; // Skip over the node being deleted
    }
    Node* next_node = current->next;
    delete current; // Delete the current node
    return next_node; // Return the next node in the list
}

Node* rotation(Node*& node, int min, int max) {
    Node* current = node;
    Node* prev = nullptr;

    while (current != nullptr) {
        // 노드와 범위가 겹칠 경우
        if (!(current->max < min || current->min > max)) {
            max = std::max(current->max, max);
            min = std::min(current->min, min);

            // 현재 노드를 삭제하고 다음 노드로 이동
            current = delete_node(node, prev, current);
        }
        else {
            prev = current; // Move prev to current
            current = current->next; // Move to next node
        }
    }

    // 새로운 노드 생성 및 연결
    Node* new_node = new Node(min, max);
    new_node->next = node; // Insert new node at the head
    node = new_node; // Update head
    return node;
}

Node* insert(Node* node, int min, int max) {
    if (node == nullptr) {
        Node* new_node = new Node(min, max);
        return new_node;
    }
    return rotation(node, min, max);
}

void print(Node* node) {
    Node* current = node;
    int sum = 0;
    while (current != nullptr) {
        sum += (current->max - current->min);
        current = current->next;
    }
    std::cout << sum;
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
