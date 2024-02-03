#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    dp = vector<int>(N + 1, 0);
    dp[0] = 1;
    dp[2] = 3;

    for(int i=4; i <= N; i += 2) {
        dp[i] += dp[i - 2] * 4 - dp[i - 4];
    }
    cout << dp[N] << '\n';
}