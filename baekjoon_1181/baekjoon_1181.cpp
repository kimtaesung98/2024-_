#include <iostream>
#include <string>
#include <vector>
using namespace std;

class root {
public:
    int n;
    string str;
    root* next;
    root* prev;
    root(int n,string str) : n(n),str(str),next(nullptr), prev(nullptr) {}
};
root* insert(root* roots,root* r) {
    if (roots == nullptr) {
        return roots = r;
    }
    if (roots->n < r->n) {
        roots->next = insert(roots->next, r);
    }
    if (roots->n >= r->n) {
        roots->prev = insert(roots->prev, r);
    }
    return roots;
}
void print_tree(root *roots) {
    if (roots == nullptr)return;
    print_tree(roots->next);
    cout << roots->n << " ";
    print_tree(roots->prev);
}
int main() {
    int n;
    string str;
    root* roots =  nullptr;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        roots = insert(roots,new root(str.length(),str));
    }
    print_tree(roots);
}
