#include <iostream>
#include <vector>

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


    Node* _remove(Node* node, int key) {
        if (node == nullptr) {
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
        }
        else if (node->right != nullptr) {
            Node* temp = node;
            node = node->right;
            delete temp;
            temp = nullptr;
        }
        else {
            delete node;
            node = nullptr;
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
        }
        else {
        }
        return _search(root, key);
    }

    void print_tree() {
        _print_tree(root, 0);
    }

    int levels_count() {
        if (root == nullptr) {
            return 0;
        }
        int level = 0;
        vector<Node*> vertex;
        vertex.push_back(root);
        while (!vertex.empty()) {
            level++;
            vector<Node*> new_vertex;
            for (Node* node : vertex) {
                if (node->left != nullptr) {
                    new_vertex.push_back(node->left);
                }
                if (node->right != nullptr) {
                    new_vertex.push_back(node->right);
                }
            }
            vertex.clear();
            for (Node* node : new_vertex) {
                vertex.push_back(node);
            }
        }
        return level;

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

    cout << tree.levels_count();
    return 0;
}