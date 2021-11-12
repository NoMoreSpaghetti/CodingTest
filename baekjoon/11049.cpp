#include <iostream>
using namespace std;

int N;
int ary[501];
int dp[501][501] = {0};

int func(int n) {
    for(int i=1; i < n; i++) {
        dp[i][i + 1] = ary[i - 1] * ary[i] * ary[i + 1];
    }
    for(int i=2; i < n; i++) {
        for(int j=1; i + j <= n; j++) {
            dp[j][i + j] = dp[j][j] + dp[j + 1][i + j] + ary[j - 1] * ary[j] * ary[i + j];
            for(int k=j + 1; k < i + j; k++) {
                dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + ary[j - 1] * ary[k] * ary[i + j]);
            }
        }
    }
    return dp[1][n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0; i < N; i++) {
        cin >> ary[i] >> ary[i + 1];
    }

    cout << func(N) << '\n';
}