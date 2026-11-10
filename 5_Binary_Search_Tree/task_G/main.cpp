#include <iostream>
#include <queue>

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

    void _parent_having_2_childs(Node* node){
        if (node == nullptr){
            return;
        }
        _parent_having_2_childs(node->left);
        if (node->left != nullptr && node->right != nullptr){
            cout << node->data << '\n';
        }
        _parent_having_2_childs(node->right);
    }


public:
    ~BinarySearchTree() {
        _clear(root);
    }

    void insert(int key) {
        root = _insert(root, key);
    }

    void parent_having_2_childs(){
        _parent_having_2_childs(root);
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

    tree.parent_having_2_childs();

    return 0;
}