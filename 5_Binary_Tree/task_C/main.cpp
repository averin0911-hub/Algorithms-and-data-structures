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
    int size = 0;

    Node* _insert(Node* node, int key) {
        if (node == nullptr) {
            size++;
            Node* new_node = new Node{key};
            return new_node;
        }
        if (key < node->data) {
            node->left = _insert(node->left, key);
        }
        else if (key > node->data){
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

public:
    ~BinarySearchTree() {
        _clear(root);
    }

    void insert(int key) {
        root = _insert(root, key);
    }

    int get_size() {
        return size;
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

    cout << tree.get_size();
    return 0;
}