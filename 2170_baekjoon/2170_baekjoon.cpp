#include <iostream>
class Node {
public:
	int max;
	int min;
	Node* next;
	Node* prev;
	Node(int max, int min) :min(min), max(max), next(nullptr), prev(nullptr) {}
};
bool compare() {//비교함수
	
}
Node* rotation(Node* node, int x, int y) {
	Node* current = node;
	Node* new_node;
	do {
		if (compare) {
			new_node = merge(node, x, y);
			current = node;
		}
		current = current->next;
	} while (current != node);
	return node;
}
void delete_node(Node* node) {//노드 삭제
	Node* node_next = node->next;
	Node* node_prev = node->prev;
	node_next->prev = node_prev;
	node_prev->next = node_next;
	node = nullptr;
}
Node* merge(Node* node, int x, int y) {//해당 노드의 비교 병합.
	if (node == nullptr) {// 범위값이 커서 모든 노드가 사라진 경우
		Node* new_node = new Node(x, y);
		return new_node;
	}

	if (node->max > x || node->min > y) {
		//범위 밖의 노드, 새 노드 형성후에 결합
		Node* new_node = new Node(x, y);
		return new_node;
	}
	else if (node->max >= x && node->min <= y)return node;
	//기존 노드의 범위 내부만큼, 변화 없음

	// 이곳에서 재귀함수 시작, 재귀 함수 만들기.
	delete_node(node);
	int max = (node->max > x) ? node->max : x;
	int min = (node->min > y) ? y : node->min;
	return merge(node,max,min);// 새로운 범위의 노드 형성및 기존 노드 삭제
}
Node* insert(Node* node, int x, int y) {//키값 삽입 수정 필요, 병합 함수
	if (node == nullptr) {
		Node* new_node = new Node(x, y);
		new_node->next = new_node;
		new_node->prev = new_node;
		return new_node;
	}
	Node* new_node = rotation(node, x, y);
	return new_node;
}
void print(Node* node) {
	if (node == nullptr)return;

	Node* current = node;
	do {
		printf("%d %d\n", current->min, current->max);
		current = current->next;
	} while (current != node);
}
int main() {
	int n, a, b; scanf_s("%d", &n);
	Node* node = nullptr;
	for (int i = 0; i < n; i++) {
		scanf_s("%d %d", &a, &b);
		node = insert(node, a, b);
	}
	print(node);
}