#include <iostream>
using namespace std;

int dp[100][10][4] = {0};

int my_func(int N) {
    for(int i=1; i < 9; i++) {
        dp[0][i][0] = 1;
    }
    dp[0][9][2] = 1;

    for(int i = 1; i < N; i++) {
        for(int j=1; j <= 8; j++) {
            for(int k=0; k <= 3; k++) {
                dp[i][j][k] += dp[i - 1][j - 1][k];
                dp[i][j][k] += dp[i - 1][j + 1][k];
                dp[i][j][k] %= 1000000000;
            }
        }
        for(int k=0; k <= 3; k++) {
            dp[i][0][k | 1] += dp[i - 1][1][k];
            dp[i][9][k | 2] += dp[i - 1][8][k];
            dp[i][0][k | 1] %= 1000000000;
            dp[i][9][k | 2] %= 1000000000;
        }
    }

    int ans = 0;

    for(int i=0; i <= 9; i++) {
        ans += dp[N - 1][i][3];
        ans %= 1000000000;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    cout << my_func(N) << '\n';
}