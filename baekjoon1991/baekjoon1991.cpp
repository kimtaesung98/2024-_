#include <iostream>

using namespace std;

class Tree {
public:
    char node;
    Tree* left;
    Tree* right;

    Tree() : node(0), left(nullptr), right(nullptr) {}

    Tree* insert(Tree* root, char c, char l, char r) {
        if (!root) {
            root = new Tree;
            root->node = c;
        }
        if (root->node == c) {
            if (l != '.') root->left = insert(root->left, l, '.', '.');
            if (r != '.') root->right = insert(root->right, r, '.', '.');
        }
        else {
            if (root->left) insert(root->left, c, l, r);
            if (root->right) insert(root->right, c, l, r);
        }
        return root;
    }

    void inorder(Tree* root) {
        if (root) {
            inorder(root->left);
            cout << root->node;
            inorder(root->right);
        }
    }

    void preorder(Tree* root) {
        if (root) {
            cout << root->node;
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(Tree* root) {
        if (root) {
            postorder(root->left);
            postorder(root->right);
            cout << root->node;
        }
    }
};

int main() {
    int num;
    cin >> num;
    Tree* root = nullptr;
    Tree tree;

    for (int i = 0; i < num; ++i) {
        char c, l, r;
        cin >> c >> l >> r;
        root = tree.insert(root, c, l, r);
    }

    tree.preorder(root);
    cout << endl;
    tree.inorder(root);
    cout << endl;
    tree.postorder(root);
    cout << endl;

    return 0;
}
