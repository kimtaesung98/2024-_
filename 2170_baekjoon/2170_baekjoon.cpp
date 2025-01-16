#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 노드 클래스 정의
class Node {
public:
    int min;  // 저장할 최소값
    int max;  // 저장할 최대값
    Node* next; // 다음 노드를 가리키는 포인터

    Node(int minVal, int maxVal) : min(minVal), max(maxVal), next(nullptr) {}
};

// 링크드 리스트 클래스 정의
class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void add(int minVal, int maxVal) {
        Node* newNode = new Node(minVal, maxVal);
        if (!head) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void calculateDistances(int& totalDistance, int& lastMin, int& lastMax) {
        Node* current = head;
        if (!current) return; // 리스트가 비어있으면 종료

        lastMin = current->min;  // 시작 노드의 최소값
        lastMax = current->max;  // 시작 노드의 최대값
        totalDistance = 0;       // 총 거리 초기화

        while (current && current->next) {
            Node* nextNode = current->next;

            if (lastMax >= nextNode->min) {
                // 현재 노드의 max값이 다음 노드의 min값보다 크거나 같을 경우 연결
                lastMax = max(lastMax, nextNode->max); // 최대값 최신화
            }
            else {
                // 연결되지 않는 경우, 현재까지의 유효한 거리 계산
                int distance = lastMax - lastMin;
                totalDistance += distance;

                // 새로운 구간의 시작
                lastMin = nextNode->min;
                lastMax = nextNode->max;
            }

            current = nextNode; // 다음 노드로 이동
        }

        // 마지막 구간의 거리 계산
        int finalDistance = lastMax - lastMin;
        totalDistance += finalDistance;
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    int n;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        // 최소값과 최대값을 리스트에 추가
        if (a > b) swap(a, b); // 항상 a가 최소값이 되도록 조정
        list.add(a, b);
    }

    int totalDistance = 0;
    int lastMin = 0, lastMax = 0;

    // 거리 계산
    list.calculateDistances(totalDistance, lastMin, lastMax);

    // 결과값 출력 (전체 거리)
    cout << totalDistance << endl;

    // 메모리 정리
    list.clear();

    return 0;
}
