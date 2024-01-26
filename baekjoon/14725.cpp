#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N;

class Node {
public:
    Node* AddChild(string name, Node* child) {
        auto iter = childs.find(name);
        if(iter != childs.end()) {
            return iter->second;
        } else {
            childs.insert({name, child});
            return child;
        }
    }

    void Print(int depth=0) {
        for(auto& child: childs) {
            for(int i=0; i < depth; i++) {
                cout << "--";
            }
            cout << child.first << '\n';
            child.second->Print(depth + 1);
        }
    }
private:
    map<string, Node*> childs;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int K;
    string s;
    Node* root = new Node();

    for(int i=0; i < N; i++) {
        cin >> K;
        
        Node* parent = root;
        
        for(int k=0; k < K; k++) {
            cin >> s;
            parent = parent->AddChild(s, new Node());
        }
    }

    root->Print();
}