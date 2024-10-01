#include <iostream>
#include <vector>
#define DIV_VAL (1000000007)
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<long long>> dp(N, vector<long long>(3, 0));
    vector<vector<long long>> dp2(N, vector<long long>(2, 0));

    long long answer = 0;
    dp[0][0] = 1;

    if(N > 1) {    
        dp[1][0] = 1;
        dp[1][1] = 1;
        dp[1][2] = 1;

        dp2[1][0] = 1;
        dp2[1][1] = 1;

        if(N > 2) {
            dp[2][0] = 3;
            dp[2][1] = 3;
            dp[2][2] = 2;

            dp2[2][0] = 2;
            dp2[2][1] = 2;
        }

        for(int i=3; i < N; i++) {
            // 이전에 어떤 높이여도 상관없음
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % DIV_VAL;
            // 이전 높이가 1이었으면 그 전 높이는 0이어야 함
            // 이전 높이가 2였으면 그 전 높이는 마찬가지로 0이어야 함
            dp[i][1] = (dp[i - 1][0] + dp[i - 2][0] * 2) % DIV_VAL;
            // 이전 높이가 1이었으면 그 전 높이는 0이어야 함
            // 이전 높이가 2일수 없음
            dp[i][2] = (dp[i - 1][0] + dp[i - 2][0]) % DIV_VAL;
            
            dp2[i][0] = (dp2[i - 1][0] + dp2[i - 1][1]) % DIV_VAL;
            dp2[i][1] = (dp2[i - 1][0] + dp2[i - 2][0]) % DIV_VAL;
        }
        answer = (dp[N - 1][0] + dp[N - 1][1] + dp[N - 1][2] - dp2[N - 1][0] - dp2[N - 1][1] + DIV_VAL) % DIV_VAL;
    }

    cout << answer << '\n';
}