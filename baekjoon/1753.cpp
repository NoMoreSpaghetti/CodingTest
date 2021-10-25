#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, long long>> g[20001];
long long shortest[20001];

int V, E, K;

void dijkstra(int start) {
    fill_n(shortest, V + 1, LLONG_MAX);
    shortest[start] = 0;

    priority_queue<pair<long long, int>> pq;
    pq.push(make_pair(0, start));
    while(!pq.empty()) {
        long long dist = -pq.top().first;
        int current = pq.top().second;
        pq.pop();
        if(shortest[current] < dist) {
            continue;
        }
        for(int i=0; i < g[current].size(); i++) {
            int next = g[current][i].first;
            long long next_dist = g[current][i].second + dist;
            if(shortest[next] > next_dist) {
                shortest[next] = next_dist;
                pq.push(make_pair(-next_dist, next));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E >> K;

    int start, dest;
    long long dist;
    for(int i=0; i < E; i++) {
        cin >> start >> dest >> dist;
        g[start].push_back(make_pair(dest, dist));
    }

    dijkstra(K);

    for(int i=1; i <= V; i++) {
        if(shortest[i] == LLONG_MAX) {
            cout << "INF" << '\n';
        } else {
            cout << shortest[i] << '\n';
        }
    }
}