#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> vec(N + 1, 0);
    vector<int> dp(N + 1, INT32_MAX);

    for(int i=1; i <= N; i++) {
        cin >> vec[i];
    }

    dp[0] = dp[0];
    dp[1] = vec[1];

    for(int i=2; i <= N; i++) {
        for(int j=1; j <= i / 2; j++) {
            dp[i] = min(dp[i], dp[i - j] + dp[j]);
        }
        dp[i] = min(dp[i], vec[i]);
    }

    cout << dp[N] << '\n';
}