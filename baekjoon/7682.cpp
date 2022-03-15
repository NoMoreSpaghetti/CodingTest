#include <iostream>
using namespace std;

int bitCount(int x) {
    if(x == 0) return 0;
    return x % 2 + bitCount(x / 2);
}

void check_valid(const string& s) {
    int board[3][3] = {0};
    int sum = 0;
    int num_x = 0;
    int num_o = 0;
    int col_sums[3] = {0};
    int row_sums[3] = {0};
    int diagonal_sums[2] = {0};
    bool valid = true;

    for(int i=0; i < 3; i++) {
        for(int j=0; j < 3; j++) {
            char stone = s[i * 3 + j];
            if(stone == 'X') {
                num_x++;
                board[i][j] = 1;
            } else if(stone == 'O') {
                num_o++;
                board[i][j] = -1;
            } else {
                continue;
            }
            sum += board[i][j];
            row_sums[i] += board[i][j];
            col_sums[j] += board[i][j];
            if(i == j) {
                diagonal_sums[0] += board[i][j];
            }
            if(i == 2 - j) {
                diagonal_sums[1] += board[i][j];
            }
        }
    }

    if(sum != 0 && sum != 1) {
        // 돌의 개수가 안맞는 경우
        valid = false;
    } else {
        int x_bingo = 0;
        int o_bingo = 0;

        for(int i=0; i < 3; i++) {
            if(col_sums[i] == 3) {
                x_bingo |= 1 << i;
            } else if(col_sums[i] == -3) {
                o_bingo |= 1 << i;
            }

            if(row_sums[i] == 3) {
                x_bingo |= 1 << (3 + i);
            } else if(row_sums[i] == -3) {
                o_bingo |= 1 << (3 + i);
            }
        }

        for(int i=0; i < 2; i++) {
            if(diagonal_sums[i] == 3) {
                x_bingo |= 1 << (6 + i);
            } else if(diagonal_sums[i] == -3) {
                o_bingo |= 1 << (6 + i);
            }
        }

        if(x_bingo > 0 && o_bingo > 0) {
            // 양 플레이어 모두 빙고가 있는 경우
            valid = false;
        } else if(x_bingo == 0 && o_bingo == 0) {
            // 양 플레이어 모두 빙고가 없는 경우
            if(num_x + num_o < 9) {
                // 빈 공간이 있으면 false
                valid = false;
            }
        } else if(o_bingo > 0 && sum == 1) {
            // O의 승리인데 X돌이 더 많은 경우
            valid = false;
        } else if(x_bingo > 0 && sum == 0) {
            // X의 승리인데 돌 개수가 같은 경우
            valid = false;
        } else {
            const int& bingo = (x_bingo > 0) ? x_bingo : o_bingo;
            if(bitCount(bingo) > 2) {
                // 빙고가 3개 이상 존재하는 경우
                valid = false;
            } else if(bitCount(bingo & ((1 << 3) - 1)) > 1) {
                // 가로 빙고가 두 개 이상 있는 경우
                valid = false;
            } else if(bitCount(bingo & (((1 << 6) - 1) - ((1 << 3) - 1))) > 1) {
                // 세로 빙고가 두 개 이상 있는 경우
                valid = false;
            }
        }
    }

    if(valid) {
        cout << "valid" << '\n';
    } else {
        cout << "invalid" << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    while(s.compare("end")) {
        check_valid(s);
        cin >> s;
    }
}