#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<int> dists;

int N, M, K, X;

void Dijkstra(int start) {
    queue<int> pq;
    pq.push(start);

    dists[start] = 0;

    while(!pq.empty()) {
        int cur = pq.front();
        pq.pop();

        for(int i=0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            int next_dist = 1 + dists[cur];
            if(next_dist < dists[next]) {
                dists[next] = next_dist;
                pq.push(next);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K >> X;

    graph = vector<vector<int>>(N + 1, vector<int>());
    dists = vector<int>(N + 1, INT32_MAX);

    int A, B;
    for(int i=0; i < M; i++) {
        cin >> A >> B;
        graph[A].push_back(B);
    }

    Dijkstra(X);

    bool printed = false;
    for(int i=1; i <= N; i++) {
        if(dists[i] == K) {
            cout << i << '\n';
            printed = true;
        }
    }

    if(!printed) {
        cout << "-1";
    }
}