// 참고: https://yabmoons.tistory.com/229
#include <iostream>
#include <queue>
using namespace std;

int N, M;
char board[10][10];
int d_y[] = {-1, 0, 1, 0};
int d_x[] = {0, 1, 0, -1};
int opposite_direction[] = {2, 3, 0, 1, 4};
int hole_y = 0, hole_x = 0;
int ans = 11;


void simulate_recursive(pair<int, int> r, pair<int, int> b, int cnt, int prev_direction) {
    if(cnt >= ans || cnt == 10) {
        return;
    } else {
        int return_val = -1;
        for(int i=0; i < 4; i++) {
            if(i == prev_direction || i == opposite_direction[prev_direction]) {
                continue;
            } else {
                int new_r_y = r.first;
                int new_r_x = r.second;
                int new_b_y = b.first;
                int new_b_x = b.second;
                
                int r_move_cnt = 0;
                int b_move_cnt = 0;
                bool r_in_hole = false;
                bool b_in_hole = false;

                // 빨간 공 이동
                while(board[new_r_y + d_y[i]][new_r_x + d_x[i]] != '#') {
                    new_r_y += d_y[i];
                    new_r_x += d_x[i];
                    r_move_cnt++;
                    if(new_r_y == hole_y && new_r_x == hole_x) {
                        r_in_hole = true;
                    }
                }

                // 파란 공 이동
                while(board[new_b_y + d_y[i]][new_b_x + d_x[i]] != '#') {
                    new_b_y += d_y[i];
                    new_b_x += d_x[i];
                    b_move_cnt++;
                    if(new_b_y == hole_y && new_b_x == hole_x) {
                        b_in_hole = true;
                    }
                }

                // 두 공위 위치가 겹칠 경우
                // 더 많이 움직인 공을 반대 방향으로 한 번 이동
                if(new_r_y == new_b_y && new_r_x == new_b_x) {
                    if(r_move_cnt > b_move_cnt) {
                        new_r_y -= d_y[i];
                        new_r_x -= d_x[i];
                        r_move_cnt--;
                    } else if(b_move_cnt > r_move_cnt) {
                        new_b_y -= d_y[i];
                        new_b_x -= d_x[i];
                        b_move_cnt--;
                    }
                }

                // 공이 이동을 했을 시
                if(r_move_cnt > 0 || b_move_cnt > 0) {
                    // 파란 공이 빠졌을 시
                    if(b_in_hole) {
                        continue;
                    }
                    // 빨간 공이 빠졌을 시
                    else if(r_in_hole) {
                        ans = min(ans, cnt + 1);
                        continue;
                    } else {
                        simulate_recursive({new_r_y, new_r_x}, {new_b_y, new_b_x}, cnt + 1, i);
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r_y = 0, r_x = 0;
    int b_y = 0, b_x = 0;

    cin >> N >> M;
    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            cin >> board[i][j];
            switch(board[i][j]) {
                case 'R':
                    r_y = i;
                    r_x = j;
                    board[i][j] = '.';
                    break;
                case 'B':
                    b_y = i;
                    b_x = j;
                    board[i][j] = '.';
                    break;
                case 'O':
                    hole_y = i;
                    hole_x = j;
                    board[i][j] = '.';
                    break;
            }
        }
    }

    simulate_recursive({r_y, r_x}, {b_y, b_x}, 0, 4);

    if(ans == 11) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
}