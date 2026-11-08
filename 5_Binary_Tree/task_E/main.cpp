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

    void _lnr(Node* node) {
        if (node == nullptr) {
            return;
        }
        _lnr(node->left);
        cout << node->data << '\n';
        _lnr(node->right);
    }


public:
    ~BinarySearchTree() {
        _clear(root);
    }

    void insert(int key) {
        root = _insert(root, key);
    }

    void lnr() {
        _lnr(root);
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
    tree.lnr();

    return 0;
}