#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, L, R;
vector<vector<int>> board;
vector<vector<bool>> visited;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void BFS(pair<int, int> start) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> vec;
    q.push(start);
    vec.push_back(start);
    int sum = 0;

    visited[start.first][start.second] = true;

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        sum += board[cur.first][cur.second];

        for(int i=0; i < 4; i++) {
            pair<int, int> next = {cur.first + dy[i], cur.second + dx[i]};
            if(next.first < 0 || next.first >= N || next.second < 0 || next.second >= N) continue;
            if(visited[next.first][next.second]) continue;

            int difference = abs(board[cur.first][cur.second] - board[next.first][next.second]);

            if(difference < L || difference > R) continue;

            visited[next.first][next.second] = true;
            q.push(next);
            vec.push_back(next);
        }
    }

    int divided_num = sum / vec.size();

    for(auto& cur: vec) {
        board[cur.first][cur.second] = divided_num;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> L >> R;

    board = vector<vector<int>>(N, vector<int>(N, 0));
    visited = vector<vector<bool>>(N, vector<bool>(N, false));

    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 0;
    while(true) {
        int cnt = 0;
        visited = vector<vector<bool>>(N, vector<bool>(N, false));

        for(int i=0; i < N; i++) {
            for(int j=0; j < N; j++) {
                if(visited[i][j]) continue;
                cnt++;
                BFS({i, j});
            }
        }
        if(cnt == N * N) {
            break;
        }
        ans++;
    }

    cout << ans << '\n';
}