#include <iostream>
using namespace std;

int T;
int N;
int score[100000][2];
int dp[100000][2];

int get_max_score() {
    dp[0][0] = score[0][0];
    dp[0][1] = score[0][1];
    dp[1][0] = dp[0][1] + score[1][0];
    dp[1][1] = dp[0][0] + score[1][1];
    for(int n=2; n < N; n++) {
        dp[n][0] = max(dp[n-2][1], dp[n-1][1]) + score[n][0];
        dp[n][1] = max(dp[n-2][0], dp[n-1][0]) + score[n][1];
    }

    return max(dp[N-1][0], dp[N-1][1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int t=0; t < T; t++) {
        cin >> N;
        for(int n=0; n < N; n++) {
            cin >> score[n][0];
        }
        for(int n=0; n < N; n++) {
            cin >> score[n][1];
        }
        cout << get_max_score() << '\n';
    }
}