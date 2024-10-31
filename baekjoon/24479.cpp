#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int N, M, R;
vector<vector<int>> graph;
vector<int> ans;
vector<bool> visited;
int idx = 1;

void DFS(int start) {
    visited[start] = true;
    ans[start] = idx++;
    for(auto& next : graph[start]) {
        if(!visited[next]) DFS(next);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> R;

    graph = vector<vector<int>>(N + 1, vector<int>());
    ans = vector<int>(N + 1, 0);
    visited = vector<bool>(N + 1, false);

    int u, v;
    for(int i=0; i < M; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    DFS(R);

    for(int i=1; i <= N; i++) {
        cout << ans[i] << '\n';
    }
}