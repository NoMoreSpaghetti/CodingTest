#include <iostream>
using namespace std;

int N;
int house[17][17];
int dp[3][17][17] = {0};

enum State {
    PIPE_HORIZONTAL = 0,
    PIPE_VERTICAL = 1,
    PIPE_DIAGONAL = 2,
};

int get_num_move_pipe() {
    dp[PIPE_HORIZONTAL][1][2] = 1;

    // 첫 줄 계산
    for(int i=3; i <= N; i++) {
        if(house[1][i] == 1) {
            break;
        }
        dp[PIPE_HORIZONTAL][1][i] = 1;
    }
    // 두 번째 줄부터 마지막 줄까지 계산
    // j는 항상 1보다 크다
    for(int i=2; i <= N; i++) {
        for(int j=2; j <= N; j++) {
            if(house[i][j] == 1) {
                continue;
            }
            // 가로
            dp[PIPE_HORIZONTAL][i][j] = dp[PIPE_HORIZONTAL][i][j-1];
            dp[PIPE_HORIZONTAL][i][j] += dp[PIPE_DIAGONAL][i][j-1];
            // 세로
            dp[PIPE_VERTICAL][i][j] = dp[PIPE_VERTICAL][i-1][j];
            dp[PIPE_VERTICAL][i][j] += dp[PIPE_DIAGONAL][i-1][j];
            // 대각선
            // j는 항상 1보다 크다
            // 두 번째 줄부터 계산하므로 i는 1보다 크다
            if(house[i-1][j] != 1 && house[i][j-1] != 1) {
                dp[PIPE_DIAGONAL][i][j] = dp[PIPE_HORIZONTAL][i-1][j-1];
                dp[PIPE_DIAGONAL][i][j] += dp[PIPE_VERTICAL][i-1][j-1];
                dp[PIPE_DIAGONAL][i][j] += dp[PIPE_DIAGONAL][i-1][j-1];
            }
        }
    }

    int ans = 0;
    for(int i=0; i < 3; i++) {
        ans += dp[i][N][N];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i=1; i <= N; i++) {
        for(int j=1; j <= N; j++) {
            cin >> house[i][j];
        }
    }

    cout << get_num_move_pipe() << '\n';
}