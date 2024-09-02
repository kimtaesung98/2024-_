#include <iostream>
class Node {
public:
	int max;
	int min;
	Node* next;
	Node* prev;
	Node(int max, int min) :min(min), max(max), next(nullptr), prev(nullptr) {}
};
bool compare(Node* node, Node* new_node) {//비교함수
	if (node->max < new_node->min || node->min > new_node->max)return false;
	return true;
}
void delete_node(Node* node) {//노드 삭제
	Node* node_next = node->next;
	Node* node_prev = node->prev;
	node_next->prev = node_prev;
	node_prev->next = node_next;
	delete node;
}
Node* merge(Node* node,int x,int y) {//노드 병합, 수정 필요
	Node* current = node;
	Node* new_node = new Node(x, y);
	while (current != current->prev) {
		current = current->next;
		if (compare(current, new_node)) {
			delete_node(current);
			int max = (node->max < new_node->max) ? new_node->max : node->max;
			int min = (node->min < new_node->min) ? node->min : new_node->min;
			new_node = new Node(max, min);
			return new_node;
		}
	}
	return new_node;
}
Node* insert(Node* node,int x,int y) {//키값 삽입 수정 필요, 병합 함수
	if (node == nullptr) {
		Node* new_node = new Node(x,y);
		new_node->next = new_node;
		new_node->prev = new_node;
		return new_node;
	}
	Node* new_node = merge(node,x, y);
	node->prev = new_node;
	new_node->next = node;
}

int main(){
	int n,a,b; scanf_s("%d", &n);
	Node* node = nullptr;
	for (int i = 0; i < n; i++) {
		scanf_s("%d %d", &a, &b);
		node = insert(node,a,b);
	}
}