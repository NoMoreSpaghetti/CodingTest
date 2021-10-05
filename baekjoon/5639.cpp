#include <iostream>
using namespace std;


class Node {
    public:
        int val;
        Node* left;
        Node* right;
        Node* p;
    
        Node(int val);
        void set_left(Node* left);
        void set_right(Node* right);
        void set_p(Node* p);
};

Node::Node(int val) {
    this->val = val;
    this->left = nullptr;
    this->right = nullptr;
    this->p = nullptr;
}

void Node::set_left(Node* left) {
    this->left = left;
    if(left != nullptr) {
        left->set_p(this);
    }
}

void Node::set_right(Node* right) {
    this->right = right;
    if(right != nullptr) {
        right->set_p(this);
    }
}

void Node::set_p(Node* p) {
    this->p = p;
}

void postorder_traverse(Node* node) {
    if(node->left != nullptr)
        postorder_traverse(node->left);
    if(node->right != nullptr)
        postorder_traverse(node->right);
    cout << node->val << '\n';
}

Node* build_tree(int preorder_list[], int start, int end) {
    if(start > end) {
        return nullptr;
    }

    int val = preorder_list[start];
    Node* cur_node = new Node(val);

    if(start == end) {
        return cur_node;
    }

    int inorder_idx = start;
    while(end >= inorder_idx && preorder_list[inorder_idx] <= val) {
        inorder_idx++;
    }
    
    cur_node->set_left(build_tree(preorder_list, start + 1, inorder_idx - 1));
    cur_node->set_right(build_tree(preorder_list, inorder_idx, end));

    return cur_node;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int preorder_list[10000];
    int idx = 0;

    while(cin >> preorder_list[idx]) {
        idx++;
    }

    Node* root = build_tree(preorder_list, 0, idx - 1);

    postorder_traverse(root);

    return 0;
}