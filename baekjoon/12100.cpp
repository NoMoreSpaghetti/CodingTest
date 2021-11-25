#include <iostream>
#include <vector>
#define SWAP(a, b) do{int temp = a; a = b; b = temp;} while(0);
using namespace std;

int N;

// direction
//   0
// 3   1
//   2
int simulate(int direction, int remain_num, int max_num, vector<vector<int>>& state) {
    if(remain_num == 0) {
        return max_num;
    }

    vector<vector<int>> next_state(N, vector<int>(N, 0));

    
    if(direction == 0) { // up
        int start = 0;
        // 각 열에 대해 반복
        for(int i=0; i < N; i++) {
            int next_pos = start;
            int j = 0;
            for(; j < N - 1; j++) {
                if(state[j][i] != 0) {
                    // j 다음 수들 중 0이 아닌 수를 찾음
                    int k = j + 1;
                    for(; k < N; k++) {
                        if(state[k][i] != 0) {
                            // 찾은 수가 j번째 수와 같은 수이면
                            if(state[k][i] == state[j][i]) {
                                next_state[next_pos][i] = state[j][i] * 2;
                                max_num = max(max_num, next_state[next_pos][i]);
                                j = k;      // k + 1을 j로 설정
                            } else {
                                next_state[next_pos][i] = state[j][i];
                                // k 가 마지막 수이고 합쳐지지 않은 경우
                                j = k - 1;  // k를 j로 설정
                            }
                            next_pos++;
                            break;
                        }
                    }
                    if(k == N) {
                        next_state[next_pos][i] = state[j][i];
                        break;
                    }
                }
            }
            if(j == N - 1) {
                next_state[next_pos][i] = state[N - 1][i];
            }
        }
    } else if(direction == 2) { // down
        int start = N - 1;
        for(int i=0; i < N; i++) {
            int next_pos = start;
            int j = start;
            for(; j > 0; j--) {
                if(state[j][i] != 0) {
                    int k = j - 1;
                    for(; k >= 0; k--) {
                        if(state[k][i] != 0) {
                            if(state[k][i] == state[j][i]) {
                                next_state[next_pos][i] = state[j][i] * 2;
                                max_num = max(max_num, next_state[next_pos][i]);
                                j = k;
                            } else {
                                next_state[next_pos][i] = state[j][i];
                                j = k + 1;
                            }
                            next_pos--;
                            break;
                        }
                    }
                    if(k == -1) {
                        next_state[next_pos][i] = state[j][i];
                        break;
                    }
                }
            }
            if(j == 0) {
                next_state[next_pos][i] = state[0][i];
            }
        }
    } else if(direction == 1) { // right
        int start = N - 1;
        for(int i=0; i < N; i++) {
            int next_pos = start;
            int j = start;
            for(; j > 0; j--) {
                if(state[i][j] != 0) {
                    int k = j - 1;
                    for(; k >= 0; k--) {
                        if(state[i][k] != 0) {
                            if(state[i][k] == state[i][j]) {
                                next_state[i][next_pos] = state[i][j] * 2;
                                max_num = max(max_num, next_state[i][next_pos]);
                                j = k;
                            } else {
                                next_state[i][next_pos] = state[i][j];
                                j = k + 1;
                            }
                            next_pos--;
                            break;
                        }
                    }
                    if(k == -1) {
                        next_state[i][next_pos] = state[i][j];
                        break;
                    }
                }
            }
            if(j == 0) {
                next_state[i][next_pos] = state[i][0];
            }
        }
    } else if(direction = 3) { // left
        int start = 0;
        for(int i=0; i < N; i++) {
            int next_pos = start;
            int j = 0;
            for(; j < N - 1; j++) {
                if(state[i][j] != 0) {
                    int k = j + 1;
                    for(; k < N; k++) {
                        if(state[i][k] != 0) {
                            if(state[i][k] == state[i][j]) {
                                next_state[i][next_pos] = state[i][j] * 2;
                                max_num = max(max_num, next_state[i][next_pos]);
                                j = k;
                            } else {
                                next_state[i][next_pos] = state[i][j];
                                j = k - 1;
                            }
                            next_pos++;
                            break;
                        }
                    }
                    if(k == N) {
                        next_state[i][next_pos] = state[i][j];
                        break;
                    }
                }
            }
            if(j == N - 1) {
                next_state[i][next_pos] = state[i][N - 1];
            }
        }
    }

    bool state_changed = false;
    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            if(state[i][j] != next_state[i][j]) {
                state_changed = true;
                break;
            }
        }
        if(state_changed) {
            break;
        }
    }

    // cout << direction << ' ' << remain_num << '\n';
    // for(int i=0; i < N; i++) {
    //     for(int j=0; j < N; j++) {
    //         cout << next_state[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    if(!state_changed) {
        return max_num;
    }

    int next_state_max_num = 0;
    for(int i=0; i < 4; i++) {
        next_state_max_num = max(next_state_max_num, simulate(i, remain_num - 1, max_num, next_state));
    }

    return next_state_max_num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    int ans = 0;
    vector<vector<int>> board(N, vector<int>(N, 0));

    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            cin >> board[i][j];
            ans = max(ans, board[i][j]);
        }
    }

    for(int i=0; i < 4; i++) {
        ans = max(ans, simulate(i, 5, 0, board));
    }
    cout << ans << '\n';
}