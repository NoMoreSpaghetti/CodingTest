#include<iostream>
#include<vector>
#include<string.h>
#include<stack>
using namespace std;

class Node {
    public:
        int val;
        vector<pair<Node*, int>> v;

        Node() {}

        void set_val(int val) {
            this->val = val;
        }

        void add_line(Node* dst, int dist) {
            v.push_back(make_pair(dst, dist));
        }
};


int V;
Node nodes[100000];
bool visited[100000];

Node* dfs(Node* n, int& max_dist) {
    max_dist = 0;
    Node* max_node;

    stack<pair<Node*, int>> s;

    s.push(make_pair(n, 0));
    visited[n->val] = true;

    while(!s.empty()) {
        Node* node = s.top().first;
        int dist = s.top().second;
        s.pop();

        if(dist > max_dist) {
            max_dist = dist;
            max_node = node;
        }

        for(int i=0; i < node->v.size(); i++) {
            pair<Node*, int> p = node->v[i];
            if(visited[p.first->val] == false) {
                visited[p.first->val] = true;
                p.second += dist;
                s.push(p);
            }
        }
    }

    return max_node;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int str, dst, dist;
    cin >> V;

    for(int v=0; v < V; v++) {
        cin >> str;
        while(true) {
            cin >> dst;
            if(dst == -1) {
                break;
            }
            cin >> dist;
            nodes[str].set_val(str);
            nodes[str].add_line(&nodes[dst], dist);
            nodes[dst].add_line(&nodes[str], dist);
        }
    }

    int max_dist = 0;
    Node* n;

    memset(visited, false, sizeof(visited));
    n = dfs(&nodes[1], max_dist);

    memset(visited, false, sizeof(visited));
    n = dfs(n, max_dist);

    cout << max_dist << '\n';
}