#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int N, M, A, B, C;
bool visited[100001];
vector<pair<int, int>> v[100001];
priority_queue<pair<int, int>> pq;

int get_cost_by_prim() {
    int ans = 0, num_e = 0, cur, dist, next, next_dist, max_dist = 0;
    memset(visited, false, sizeof(visited));
    for(int i=0; i < v[1].size(); i++) {
        next = v[1][i].first;
        next_dist = v[1][i].second;
        pq.push(make_pair(-next_dist, next));
    }
    visited[1] = true;

    while(num_e < N - 1) {
        cur = pq.top().second;
        dist = -pq.top().first;
        pq.pop();

        if(visited[cur] == false) {
            visited[cur] = true;
            ans += dist;
            num_e++;
            if(dist > max_dist) {
                max_dist = dist;
            }
            for(int i=0; i < v[cur].size(); i++) {
                next = v[cur][i].first;
                next_dist = v[cur][i].second;
                if(visited[next] == false) {
                    pq.push(make_pair(-next_dist, next));
                }
            }
        }
    }
    return ans - max_dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i=0; i < M; i++) {
        cin >> A >> B >> C;
        v[A].push_back(make_pair(B, C));
        v[B].push_back(make_pair(A, C));
    }
    cout << get_cost_by_prim() << '\n';
}