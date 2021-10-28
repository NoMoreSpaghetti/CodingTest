#include <iostream>
using namespace std;

int N;
int board[15][15];
int ans = 0;

void recursive(int num_q) {
    if(num_q == 0) {
        ans++;
        return;
    }

    int v_num = N - num_q;

    for(int i=0; i < N; i++) {
        if(board[v_num][i] == 0) {
            bool can_place = true;
            // 퀸을 놓을 수 있는지 확인
            // 각 가로줄에는 퀸이 하나뿐이므로 확인할 필요 x
            // 세로줄 검사
            // 퀸보다 아래는 검사 필요 x
            for(int j=0; j < v_num; j++) {
                if(board[j][i] == 1) {
                    can_place = false;
                    break;
                }
            }
            // 왼쪽 위 대각선 검사
            if(can_place == true) {
                for(int j=max(0, v_num - i); j < v_num; j++) {
                    if(board[j][i - v_num + j] == 1) {
                        can_place = false;
                        break;
                    }
                }
            }
            // 오른쪽 위 대각선 검사
            if(can_place == true) {
                for(int j=max(0, v_num + i - N); j < v_num; j++) {
                    if(board[j][v_num + i - j] == 1) {
                        can_place = false;
                        break;
                    }
                }
            }
            if(can_place == true) {
                board[v_num][i] = 1;
                recursive(num_q - 1);
                board[v_num][i] = 0;
            }
        }
    }
}

int main() {
    cin >> N;

    recursive(N);

    cout << ans << '\n';
}