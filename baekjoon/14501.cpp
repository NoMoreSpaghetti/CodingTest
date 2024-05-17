#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, T, P;
    cin >> N;

    vector<int> dp(N + 1, 0);

    cin >> T >> P;
    if(T <= N) {
        dp[T] = max(dp[T], P);
    }
    for(int i=1; i < N; i++) {
        cin >> T >> P;
        dp[i] = max(dp[i - 1], dp[i]);
        if(i + T <= N) {
            dp[i + T] = max(dp[i + T], P + dp[i]);
        }
    }

    dp[N] = dp[N] == 0 ? dp[N - 1] : max(dp[N - 1], dp[N]);

    cout << dp[N] << '\n';
}