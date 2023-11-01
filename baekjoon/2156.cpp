#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> vec = vector<int>(n, 0);
    vector<int> dp = vector<int>(n + 2, 0);

    for(int i=0; i < n; i++) {
        cin >> vec[i];
    }

    dp[0] = vec[0];
    dp[1] = vec[0] + vec[1];
    dp[2] = max(dp[1], max(vec[2] + dp[0], vec[2] + vec[1]));

    // 3개를 연속으로 비우는 경우는 손해 (가운데 값을 포함할 수 있다)
    // 2개까지만 연속으로 비울 수 있다.
    for(int i=3; i < n; i++) {
        dp[i] = max(dp[i - 1], max(max(vec[i] + dp[i - 2], vec[i] + dp[i - 3]), vec[i] + vec[i - 1] + dp[i - 3]));
    }

    cout << dp[n - 1] << '\n';
}