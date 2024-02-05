#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K, L;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
vector<vector<int>> board;
queue<pair<int, char>> rotations;
queue<pair<int, int>> snakes;

int rotate(int cur_direction, char rotation) {
    if(rotation == 'L') {
        cur_direction += 1;
    } else {
        cur_direction -= 1;
    }
    cur_direction = (cur_direction + 4) % 4;
    return cur_direction;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    board = vector<vector<int>>(N, vector<int>(N, 0));
    int y_pos, x_pos, x;
    char c;
    for(int i=0; i < K; i++) {
        cin >> y_pos >> x_pos;
        board[y_pos - 1][x_pos - 1] = 1;
    }

    cin >> L;
    for(int i=0; i < L; i++) {
        cin >> x >> c;
        rotations.push({x, c});
    }

    int direction_idx = 1;
    pair<int, int> cur = {0, 0};
    snakes.push({0, 0});
    int time = 0;
    while(true) {
        cur.first += dy[direction_idx];
        cur.second += dx[direction_idx];

        /// 게임 종료 검사
        // 벽과 충돌 검사
        if(cur.first < 0 || cur.first >= N || cur.second < 0 || cur.second >= N) {
            break;
        }

        // 몸과 충돌 검사
        if(board[cur.first][cur.second] == 2) {
            break;
        }
        
        snakes.push(cur);
        // 사과를 먹지 않은 경우 꼬리 제거
        if(board[cur.first][cur.second] != 1) {
            pair<int, int>& tail = snakes.front();
            board[tail.first][tail.second] = 0;
            snakes.pop();
        }
        
        board[cur.first][cur.second] = 2;
        
        time++;

        if(time == rotations.front().first) {
            direction_idx = rotate(direction_idx, rotations.front().second);
            rotations.pop();
        }
    }
    cout << time + 1 << '\n';
}