#include <iostream>
#include <vector>
using namespace std;

int N;

int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dx[8] = {-1, 0, 1, -1, -1, 0, 1, 1};

vector<vector<char>> board;

int get_num(int y, int x) {
    int num = 0;

    for(int i=0; i < 8; i++) {
        int cur_direction_num = 0;
        pair<int, int> next = {y + dy[i], x + dx[i]};

        while(next.first >= 0 && next.first < N && next.second >= 0 && next.second < N) {
            if(board[next.first][next.second] == 'W') {
                cur_direction_num++;
            } else if(board[next.first][next.second] == 'B') {
                num += cur_direction_num;
                break;
            } else {
                break;
            }

            next.first += dy[i];
            next.second += dx[i];
        }
    }

    return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    board = vector<vector<char>>(N, vector<char>(N, ' '));

    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 0;
    pair<int, int> ans_pos = {-1, -1};
    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            if(board[i][j] == '.') {
                int cur_num = get_num(i, j);
                if(cur_num > ans) {
                    ans = cur_num;
                    ans_pos = {i, j};
                }
            }
        }
    }

    if(ans == 0) {
        cout << "PASS" << '\n';
    } else {
        cout << ans_pos.second << ' ' << ans_pos.first << '\n';
        cout << ans << '\n';
    }
}