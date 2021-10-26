#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<pair<int, int>> v[10001];
int dists[10001];
bool visited[10001];

int dfs(int start, int &max_dist_child) {
    fill_n(dists, 10001, 0);
    fill_n(visited, 10001, false);

    int max_dist = 0;
    max_dist_child = start;
    stack<int> s;
    s.push(start);
    visited[start] = true;

    while(!s.empty()) {
        int here = s.top();
        int dist = dists[here];
        s.pop();

        for(int i=0; i < v[here].size(); i++) {
            int there = v[here][i].first;
            if(visited[there] == true) {
                continue;
            }
            int there_dist = v[here][i].second + dist;
            dists[there] = there_dist;
            if(there_dist > max_dist) {
                max_dist = there_dist;
                max_dist_child = there;
            }
            s.push(there);
            visited[there] = true;
        }
    }

    return max_dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, parent, child, cost;
    cin >> N;

    for(int i=0; i < N - 1; i++) {
        cin >> parent >> child >> cost;
        v[parent].push_back(make_pair(child, cost));
        v[child].push_back(make_pair(parent, cost));
    }

    int max_dist, max_dist_child;
    max_dist = dfs(1, max_dist_child);
    max_dist = dfs(max_dist_child, max_dist_child);

    cout << max_dist << '\n';
}