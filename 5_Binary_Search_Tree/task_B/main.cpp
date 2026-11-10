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

public:
    ~BinarySearchTree() {
        _clear(root);
    }

    void insert(int key) {
        root = _insert(root, key);
    }


    int levels_count() {
        if (root == nullptr) {
            return 0;
        }
        int level = 0;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            level++;
            int last_size = q.size();
            for (int i = 0; i < last_size; i++) {
                Node* node = q.front(); q.pop();
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
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

    cout << tree.levels_count() << "\n";
    return 0;
}