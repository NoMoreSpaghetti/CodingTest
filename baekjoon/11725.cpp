#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

int N;
vector<int> nodes[100001];
int parents[100001];

void dfs() {
    stack<int> s;
    bool visited[100001];
    memset(visited, false, sizeof(visited));
    visited[1] = true;
    s.push(1);
    while(!s.empty()) {
        int cur_node = s.top();
        s.pop();
        for(int i=0; i < (int)nodes[cur_node].size(); i++) {
            int next_node = nodes[cur_node][i];
            if(visited[next_node] == false) {
                parents[next_node] = cur_node;
                s.push(next_node);
                visited[next_node] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int a, b;
    for(int n=0; n < N - 1; n++) {
        cin >> a >> b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }

    dfs();

    for(int i=2; i <= N; i++) {
        cout << parents[i] << '\n';
    }
}