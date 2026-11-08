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
            cout << "DONE" << '\n';
            return new_node;
        }
        if (key == node->data) {
            cout << "ALREADY" << '\n';
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


    Node* _remove(Node* node, int key) {
        if (node == nullptr) {
            cout << "CANNOT" << '\n';
            return nullptr;
        }
        if (key < node->data) {
            node->left = _remove(node->left, key);
        }
        else if (key > node->data) {
            node->right = _remove(node->right, key);
        }
        else if (!(node->left == nullptr) && !(node->right == nullptr)) {
            node->data = find_max_node(node->left)->data;
            node->left = _remove(node->left, node->data);
        }
        else if (node->left != nullptr) {
            Node* temp = node;
            node = node->left;
            delete temp;
            temp = nullptr;
            cout << "DONE" << '\n';
        }
        else if (node->right != nullptr) {
            Node* temp = node;
            node = node->right;
            delete temp;
            temp = nullptr;
            cout << "DONE" << '\n';
        }
        else {
            delete node;
            node = nullptr;
            cout << "DONE" << '\n';
        }
        return node;
    }

    bool _search(Node* node, int key) {
        if (node == nullptr) {
            return false;
        }
        if (node->data == key) {
            return true;
        }
        if (key < node->data) {
            return _search(node->left, key);
        }
        return _search(node->right, key);
    }


    void _print_tree(Node* node, int level) {
        if (node == nullptr) {
            return;
        }
        _print_tree(node->left, level + 1);
        for (int i = 0; i < level; i++) {
            cout << ".";
        }
        cout << node->data << '\n';
        _print_tree(node->right, level + 1);
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

    void remove(int key) {
        root = _remove(root, key);
    }

    Node* find_max_node(Node* node) {
        if (node->right == nullptr) {
            return node;
        }
        return find_max_node(node->right);
    }

    bool search(int key) {
        if (_search(root, key)) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
        return _search(root, key);
    }

    void print_tree() {
        _print_tree(root, 0);
    }
};


int main() {
    BinarySearchTree tree;

    string op;
    while (cin >> op) {
        if (op == "ADD") {
            int x;
            cin >> x;
            tree.insert(x);
        }
        else if (op == "DELETE") {
            int x;
            cin >> x;
            tree.remove(x);
        }
        else if (op == "SEARCH") {
            int x;
            cin >> x;
            tree.search(x);
        }
        else {
            tree.print_tree();
        }
    }
    return 0;
}