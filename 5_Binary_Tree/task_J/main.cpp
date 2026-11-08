#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Node {
    int data;
    int count = 1;
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
            node->count++;
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

    void _print_tree(Node* node){
        if (node == nullptr){
            return;
        }
        _print_tree(node->left);
        cout << node->data << " " << node->count << '\n';
        _print_tree(node->right);
    }
    



public:
    ~BinarySearchTree() {
        _clear(root);
    }

    void insert(int key) {
        root = _insert(root, key);
    }

    void print_tree(){
        _print_tree(root);
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

    tree.print_tree();

}