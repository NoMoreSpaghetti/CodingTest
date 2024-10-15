#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<char>> maze;
vector<vector<int>> dists;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void Dijkstra(pair<int, int> start) {
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, start});

    dists[start.first][start.second] = 0;

    while(!pq.empty()) {
        int dist = -pq.top().first;
        pair<int, int> cur = pq.top().second;
        pq.pop();

        if(dists[cur.first][cur.second] < dist) continue;

        for(int i=0; i < 4; i++) {
            pair<int, int> next = {cur.first + dy[i], cur.second + dx[i]};
            if(next.first < 0 || next.first >= N || next.second < 0 || next.second >= M) continue;

            int next_dist = (maze[next.first][next.second] - '0') + dist;
            if(next_dist < dists[next.first][next.second]) {
                dists[next.first][next.second] = next_dist;
                pq.push({-next_dist, next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;
    maze = vector<vector<char>>(N, vector<char>(M, 0));
    dists = vector<vector<int>>(N, vector<int>(M, INT32_MAX));

    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            cin >> maze[i][j];
        }
    }

    Dijkstra({0, 0});

    cout << dists[N - 1][M - 1] << '\n';
}