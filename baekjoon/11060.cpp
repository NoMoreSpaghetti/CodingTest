#include <iostream>
using namespace std;

int N;
int maze[1000];
int dp[1000] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&dp[0], &dp[1000], 1001);

    cin >> N;

    for(int i=0; i < N; i++) {
        cin >> maze[i];
    }

    dp[0] = 0;

    for(int i=0; i < N; i++) {
        for(int j=1; j <= maze[i]; j++) {
            int& ret = dp[i + j];
            ret = min(ret, dp[i] + 1);
        }
    }

    if(dp[N - 1] == 1001) {
        cout << -1 << '\n';
    } else {
        cout << dp[N - 1] << '\n';
    }
}