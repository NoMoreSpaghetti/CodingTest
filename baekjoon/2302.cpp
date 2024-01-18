#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, inp;
    cin >> N >> M;

    vector<bool> fixed = vector<bool>(N + 1, false);
    vector<int> dp = vector<int>(N + 1, 0);

    for(int i=0; i < M; i++) {
        cin >> inp;
        fixed[inp] = true;
    }

    // dp 초기화
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i <= N; i++) {
        if(fixed[i] || fixed[i - 1]) {
            dp[i] = dp[i - 1];
        } else {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
    }

    cout << dp[N] << '\n';
}