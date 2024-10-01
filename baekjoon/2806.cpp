#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> dp(N, vector<int>(2, 0));

    string s;
    cin >> s;

    if(s[0] == 'A') {
        dp[0][1] = 1;
    } else {
        dp[0][0] = 1;
    }

    for(int i=1; i < N; i++) {
        if(s[i] == 'A') {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + 1);
            dp[i][1] = min(dp[i - 1][0] + 1, dp[i - 1][1] + 1);
        } else {
            dp[i][0] = min(dp[i - 1][0] + 1, dp[i - 1][1] + 1);
            dp[i][1] = min(dp[i - 1][0] + 1, dp[i - 1][1]);
        }
    }

    cout << dp[N - 1][0] << '\n';
}