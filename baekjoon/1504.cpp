//참고: https://blog.naver.com/ndb796/221234424646

#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

int N, E;
vector<pair<int, int>> v[801];

void dijkstra(int start, int value[], int len) {
    fill_n(value, len, INT_MAX);
    value[start] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(start, 0));
    while(!pq.empty()) {
        int current = pq.top().first;
        int distance = -pq.top().second;
        pq.pop();
        if(value[current] < distance) continue;
        for(int i=0; i < v[current].size(); i++) {
            int next = v[current][i].first;
            int next_distance = distance + v[current][i].second;
            if(value[next] > v[current][i].second + distance) {
                value[next] = next_distance;
                pq.push(make_pair(next, -next_distance));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c, v1, v2, ans;
    cin >> N >> E;

    for(int e=0; e < E; e++) {
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }
    cin >> v1 >> v2;

    int value_1[801], value_v1[801], value_v2[801];
    dijkstra(1, value_1, 801);
    if(value_1[v1] == INT_MAX || value_1[v2] == INT_MAX || value_1[N] == INT_MAX) {
        ans = -1;
    } else {
        dijkstra(v1, value_v1, 801);
        dijkstra(v2, value_v2, 801);

        int case1 = value_1[v1] + value_v1[v2] + value_v2[N];
        int case2 = value_1[v2] + value_v2[v1] + value_v1[N];

        ans = min(case1, case2);
    }

    cout << ans << '\n';
}