#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int V, E, A, B, C;
bool visited[10001];
vector<pair<int, int>> v[10001];
priority_queue<pair<int, int>> pq;

int get_cost_by_prim() {
    memset(visited, false, sizeof(visited));
    int num_e = 0, cur, next, dist, next_dist, ans = 0;
    for(int i=0; i < v[1].size(); i++) {
        next = v[1][i].first;
        dist = v[1][i].second;
        pq.push(make_pair(-dist, next));
    }
    visited[1] = true;
    while(num_e < V - 1) {
        cur = pq.top().second;
        dist = -pq.top().first;
        pq.pop();

        if(visited[cur] == false) {
            visited[cur] = true;
            ans += dist;
            num_e++;
            for(int i=0; i < v[cur].size(); i++) {
                next = v[cur][i].first;
                next_dist = v[cur][i].second;
                if(visited[next] == false) {
                    pq.push(make_pair(-next_dist, next));
                }
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    for(int i=0; i < E; i++) {
        cin >> A >> B >> C;
        v[A].push_back(make_pair(B, C));
        v[B].push_back(make_pair(A, C));
    }

    cout << get_cost_by_prim() << '\n';
}