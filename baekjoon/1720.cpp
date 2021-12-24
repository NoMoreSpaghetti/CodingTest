#include <iostream>
#include <limits.h>
using namespace std;

int N;
long long dp[31];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&dp[0], &dp[31], -1);
    cin >> N;

    long long ans;

    dp[0] = dp[1] = 1;
    for(int i=2; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] * 2;
    }

    if(N % 2 == 0) {
        ans = (dp[N] + dp[N / 2] + 2 * dp[(N - 1) / 2]) / 2;
    } else {
        ans = (dp[N] + dp[(N - 1) / 2]) / 2;
    }
    cout << ans << '\n';
}