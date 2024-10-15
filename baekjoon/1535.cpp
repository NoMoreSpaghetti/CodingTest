#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<vector<int>> dp(N + 1, vector<int>(101, 0));
    vector<int> L(N + 1, 0);
    vector<int> J(N + 1, 0);

    for(int i=1; i <= N; i++) {
        cin >> L[i];
    }

    for(int i=1; i <= N; i++) {
        cin >> J[i];
    }

    for(int i=1; i <= N; i++) {
        for(int j=1; j < 100; j++) {
            if(j >= L[i]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - L[i]] + J[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[N][99] << '\n';
}