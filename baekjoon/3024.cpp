#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<char>> board;
// 오른쪽 오른쪽대각선 아래쪽 왼쪽대각선
int dy[4] = {0, 1, 1, 1};
int dx[4] = {1, 1, 0, -1};

bool recursive_check(pair<int, int> cur, char c, int direction, int len) {
    if(len == 3) {
        return true;
    }
    
    pair<int, int> next = {cur.first + dy[direction], cur.second + dx[direction]};
    if(next.first < N && next.second < N && next.second >= 0) {
        if(board[next.first][next.second] == c) {
            if(recursive_check(next, c, direction, len + 1)) {
                return true;
            }
        }
    }
    
    return false;
}

void solution() {
    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            if(board[i][j] != '.') {
                for(int k=0; k < 4; k++) {
                    if(recursive_check({i, j}, board[i][j], k, 1)) {
                        cout << board[i][j] << '\n';
                        return;
                    }
                }
            }
        }
    }

    cout << "ongoing" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    board = vector<vector<char>>(N, vector<char>(N, 0));

    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    solution();
}