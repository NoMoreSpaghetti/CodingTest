#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board(5, vector<int>(5, 1));
vector<vector<int>> dp(6, vector<int>(6, 0));

// 열이나 행이 3보다 작은 경우를 제외하고는 계단식이 최적
// 1 0 1 1 0
// 1 1 0 1 1
// 0 1 1 0 1
// 1 0 1 1 0
// 1 1 0 1 1

// 2 * 2 = 4
// 1 * 2 = 2

int Solution(int R, int C) {
    if(R == 2 && C == 2) {
        return 4;
    }

    if(R <= 2) {
        return R * C - (C / 3) * R;
    }

    if(C <= 2) {
        return R * C - (R / 3) * C;
    }

    return max(dp[R][C], dp[C][R]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T, R, C;

    for(int i=0; i < 5; i++) {
        for(int j=(i + 1) % 3; j < 5; j += 3) {
            board[i][j] = 0;
        }
    }

    for(int i=1; i <= 5; i++) {
        for(int j=1; j <= 5; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + board[i - 1][j - 1];
        }
    }

    cin >> T;
    for(int t=1; t <= T; t++) {
        cin >> R >> C;
        int ans = Solution(R, C);

        cout << "Case #" << t << ": " << ans << '\n';
    }
}