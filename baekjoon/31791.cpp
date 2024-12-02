#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, TG, TB, X, B;
vector<string> board;
vector<vector<bool>> result_board;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

void BFS(queue<pair<pair<int, int>, int>>& q, queue<pair<pair<int, int>, int>>& buildings, vector<vector<bool>>& visited, int t) {
    while(!q.empty()) {
        pair<int, int> cur = q.front().first;
        int time = q.front().second;
        q.pop();

        if(time > t) {
            q.push({cur, time});
            break;
        }

        result_board[cur.first][cur.second] = true;

        for(int i=0; i < 4; i++) {
            pair<int, int> next = {cur.first + dy[i], cur.second + dx[i]};

            if(next.first < 0 || next.first >= N || next.second < 0 || next.second >= M) continue;
            if(visited[next.first][next.second]) continue;

            visited[next.first][next.second] = true;
            if(board[next.first][next.second] == '#') {
                buildings.push({next, time + TB + 1});
            } else {
                q.push({next, time + 1});
            }
        }
    }
}

void Solution() {
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<pair<pair<int, int>, int>> q;
    queue<pair<pair<int, int>, int>> buildings;

    // 시작 위치
    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            if(board[i][j] != '*') continue;

            q.push({{i, j}, 0});
            visited[i][j] = true;
        }
    }

    // 시뮬레이션
    for(int i=0; i <= TG; i++) {
        // 감염이 완료된 빌딩을 큐에 추가
        while(!buildings.empty() && buildings.front().second <= i) {
            q.push(buildings.front());
            buildings.pop();
        }
        BFS(q, buildings, visited, i);
    }
    
    // 정답 계산
    priority_queue<pair<int, int>> safe_locs;
    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            if(!result_board[i][j]) {
                safe_locs.push({-i - 1, -j - 1});
            }
        }
    }

    if(safe_locs.size() == 0) {
        cout << -1 << '\n';
    } else {
        while(!safe_locs.empty()) {
            cout << -safe_locs.top().first << ' ' << -safe_locs.top().second << '\n';
            safe_locs.pop();
        }
    }

    // for(int i=0; i < N; i++) {
    //     for(int j=0; j < M; j++) {
    //         cout << (result_board[i][j]);
    //     }
    //     cout << '\n';
    // }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    cin >> TG >> TB >> X >> B;

    board = vector<string>(N, "");
    result_board = vector<vector<bool>>(N, vector<bool>(M, false));

    for(int i=0; i < N; i++) {
        cin >> board[i];
    }

    // TG = 3;
    Solution();
}