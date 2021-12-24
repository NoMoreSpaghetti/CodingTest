#include <iostream>
using namespace std;

int T, N, M;
int coins[20];
int dp[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int t=0; t < T; t++) {
        fill(&dp[0], &dp[10001], 0);
        cin >> N;
        for(int i=0; i < N; i++) {
            cin >> coins[i];
        }
        cin >> M;

        for(int i=0; i < N; i++) {
            dp[coins[i]]++;
            for(int j=coins[i] + 1; j <= M; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        cout << dp[M] << '\n';
    }
}