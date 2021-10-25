#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

long long dijkstra(vector<pair<int, int>> v[], int N, int start, int dest) {
    long long costs[1001];
    fill_n(costs, 1001, LLONG_MAX);
    priority_queue<pair<int, long long>> pq;
    pq.push(make_pair(start, 0));
    costs[start] = 0;

    while(!pq.empty()) {
        int here = pq.top().first;
        long long cost = -pq.top().second;
        pq.pop();
        if(costs[here] < cost) {
            continue;
        }
        for(int i=0; i < v[here].size(); i++) {
            int there = v[here][i].first;
            long long next_cost = (long long)v[here][i].second + cost;
            if(costs[there] > next_cost) {
                costs[there] = next_cost;
                pq.push(make_pair(there, -next_cost));
            }
        }
    }
    return costs[dest];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, start, dest, cost;
    vector<pair<int, int>> v[1001];
    cin >> N >> M;

    for(int i=0; i < M; i++) {
        cin >> start >> dest >> cost;
        v[start].push_back(make_pair(dest, cost));
    }

    cin >> start >> dest;

    cout << dijkstra(v, N, start, dest) << '\n';
}