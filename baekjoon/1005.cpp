#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;

int T, N, K;
int costs[1001];
int full_costs[1001];
bool visited[1001];

void dfs(int here, vector<int> v[], stack<int>& t_s) {
    visited[here] = true;
    for(int i=0; i < v[here].size(); i++) {
        int there = v[here][i];
        if(visited[there] == false) {
            dfs(there, v, t_s);
        }
    }
    t_s.push(here);
}


stack<int> topological_sort(vector<int> v[]) {
    memset(visited, false, sizeof(visited));
    stack<int> t_s;
    for(int i=1; i <= N; i++) {
        if(visited[i] == false) {
            dfs(i, v, t_s);
        }
    }

    return t_s;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int start, dest, W;
    cin >> T;
    for(int t=0; t < T; t++) {
        vector<int> v[1001];
        cin >> N >> K;
        for(int i=1; i <= N; i++) {
            cin >> costs[i];
            full_costs[i] = costs[i];
        }
        for(int i=0; i < K; i++) {
            cin >> start >> dest;
            v[start].push_back(dest);
        }

        stack<int> t_s = topological_sort(v);

        cin >> W;
        while(!t_s.empty()) {
            int here = t_s.top();
            t_s.pop();
            int cost = full_costs[here];
            for(int i=0; i < v[here].size(); i++) {
                int there = v[here][i];
                int there_cost = costs[there];
                full_costs[there] = max(full_costs[there], cost + there_cost);
            }
        }

        cout << full_costs[W] << '\n';
    }
}