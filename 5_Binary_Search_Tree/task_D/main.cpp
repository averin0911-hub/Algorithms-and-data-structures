#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
};

class BinarySearchTree {
    Node* root = nullptr;

    Node* _insert(Node* node, int key) {
        if (node == nullptr) {
            Node* new_node = new Node{key};
            return new_node;
        }
        if (key == node->data) {
            return node;
        }
        else if (key < node->data) {
            node->left = _insert(node->left, key);
        }
        else {
            node->right = _insert(node->right, key);
        }
        return node;
    }

    void _clear(Node* node) {
        if (node == nullptr) {
            return;
        }

        _clear(node->left);
        _clear(node->right);

        delete node;
    }

    int _find_second_max(Node* node, Node* previous, int n) {
        if (node->right == nullptr and node->left == nullptr) { 
            if (previous != nullptr && n == 0) {
                return previous->data;
            }
            else if (n == 1) {
                return node->data;
            }
        }
        else if (node->right == nullptr && n == 0) {
            return _find_second_max(node->left, node, 1);
        }
        else if (node->right == nullptr && n == 1) {
            return node->data;
        }
        return _find_second_max(node->right, node, n);
    }

public:
    ~BinarySearchTree() {
        _clear(root);
    }

    void insert(int key) {
        root = _insert(root, key);
    }

    int find_second_max() {
        return _find_second_max(root, nullptr, 0);

    }

};


int main() {
    BinarySearchTree tree;

    int x;
    while (true) {
        cin >> x;
        if (x == 0) {
            break;
        }
        tree.insert(x);
    }

    cout << tree.find_second_max();

    return 0;
}