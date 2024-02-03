#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<vector<long long>> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    dp = vector<vector<long long>>(N + 1, vector<long long>(K + 1, 0));
    dp[0][0] = 1;

    // 개수를 하나씩 증가
    for(int i=1; i <= K; i++) {
        for(int j=0; j <= N; j++) {
            for(int l=0; l <= j; l++) {
                dp[j][i] += dp[j - l][i - 1];
                dp[j][i] %= 1000000000;
            }
        }
    }

    cout << dp[N][K] << '\n';
}