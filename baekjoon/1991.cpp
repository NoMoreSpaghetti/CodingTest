#include <iostream>
using namespace std;

int N;

class Node{
    public:
        char val;
        Node* left;
        Node* right;
        Node(char val) {
            this->val = val;
            this->left = nullptr;
            this->right = nullptr;
        }

        void set_child(Node* left=nullptr, Node* right=nullptr) {
            this->left = left;
            this->right = right;
        }
};

void preorder(Node* root) {
    if(root != nullptr) {
        cout << root->val;
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root) {
    if(root != nullptr) {
        inorder(root->left);
        cout << root->val;
        inorder(root->right);
    }
}

void postorder(Node* root) {
    if(root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->val;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    char val;
    Node* nodes[26];
    char node_childs[26][2];

    for(int n=0; n < N; n++) {
        cin >> val;
        cin >> node_childs[val - 'A'][0] >> node_childs[val - 'A'][1];
        nodes[val - 'A'] = new Node(val);
    }

    for(int n=0; n < N; n++) {
        char left_char = node_childs[n][0];
        char right_char = node_childs[n][1];
        Node* left = (left_char != '.') ? nodes[left_char - 'A'] : nullptr;
        Node* right = (right_char != '.') ? nodes[right_char - 'A'] : nullptr;
        nodes[n]->set_child(left, right);
    }

    Node* root = nodes[0];

    preorder(root);
    cout << '\n';
    inorder(root);
    cout << '\n';
    postorder(root);
    cout << '\n';
}