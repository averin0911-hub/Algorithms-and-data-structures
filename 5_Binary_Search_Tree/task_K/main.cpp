#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    long long data;
    Node* left = nullptr;
    Node* right = nullptr;
};

class BinarySearchTree {
    Node* root = nullptr;
    char last_op = '!';
    long long last_output;


    Node* _insert(Node* node, long long key) {
        if (node == nullptr) {
            Node* new_node = new Node{key};   
            return new_node;
        }
        if (key < node->data) {
            node->left = _insert(node->left, key);
        }
        else if (key > node->data) {
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


    int _next(Node* node, long long i, Node* res){
        if (node == nullptr){
            if (res == nullptr){
                last_output = -1;
                return -1;
            }
            return res->data;
        }
        if (node->data >= i){
            last_output = node->data;
            return _next(node->left, i, node);
        }
        return _next(node->right, i, res);
    }



    



public:
    ~BinarySearchTree() {
        _clear(root);
    }

    void insert(long long key) {
        if (last_op == '?'){
            key = (key + last_output) % (long long)1e9;
        }
        last_op = '+';
        root = _insert(root, key);
    }

    int next(long long i){
        last_op = '?';
        return _next(root, i, nullptr);
    }

};


int main() {
    BinarySearchTree tree;
    int n;
    cin >> n;

    char op;
    long long x;
    for (int i = 0; i < n; i++) {
        cin >> op >> x;
        if (op == '+') {
            tree.insert(x);
        }
        else{
            cout << tree.next(x) << '\n';
        }
    }

}