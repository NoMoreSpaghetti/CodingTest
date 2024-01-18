#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> dp(N, vector<int>(3, 0));

    // 0, 1: 해당 칸에 사자를 놓는 경우
    // 2: 0, 1 둘 다 사자가 없는 경우
    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[0][2] = 1;

    for(int i=1; i < N; i++) {
        dp[i][0] = (dp[i - 1][2] + dp[i - 1][1]) % 9901;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
    }

    cout << (dp[N - 1][0] + dp[N - 1][1] + dp[N - 1][2]) % 9901 << '\n';
}