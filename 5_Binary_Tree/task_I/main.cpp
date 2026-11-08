#include <iostream>
#include <vector>
#include <cmath>

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

    int _height_tree(Node* node){
        if (node == nullptr){
            return 0;
        }
        return 1 + max(_height_tree(node->left), _height_tree(node->right));
    }

    



public:
    ~BinarySearchTree() {
        _clear(root);
    }

    void insert(int key) {
        root = _insert(root, key);
    }

    bool is_balanced(){
        if (root == nullptr) {
            return true;
        }
        vector<Node*> vertex;
        vertex.push_back(root);
        while (!vertex.empty()) {
            vector<Node*> new_vertex;
            for (Node* node : vertex) {
                if (node->left != nullptr) {
                    new_vertex.push_back(node->left);
                }
                if (node->right != nullptr) {
                    new_vertex.push_back(node->right);
                }

                if (abs(_height_tree(node->left) - _height_tree(node->right)) > 1){
                    return false;
                }
            }
            vertex.clear();
            for (Node* node : new_vertex) {
                vertex.push_back(node);
            }
        }
        return true;
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

    bool res = tree.is_balanced();

    if (res){
        cout << "YES" << '\n';
    }
    else{
        cout << "NO" << '\n';
    }
    return 0;
}