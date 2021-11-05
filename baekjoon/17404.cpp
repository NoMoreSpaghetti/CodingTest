#include <iostream>
#include <climits>
using namespace std;

int INF = 1000001;
int N;
int costs[1000][3];
int dp[1000][3][3] = {0};

int get_min_cost() {
    for(int i=0; i < 3; i++) {
        dp[0][i][i] = costs[0][i];
        dp[0][i][(i+1)%3] = INF;
        dp[0][i][(i+2)%3] = INF;
    }
    for(int i=0; i < 3; i++) {
        int next1 = (i+1)%3;
        int next2 = (i+2)%3;
        dp[1][i][i] = INF;
        dp[1][next1][i] = dp[0][i][i] + costs[1][next1];
        dp[1][next2][i] = dp[0][i][i] + costs[1][next2];
    }
    for(int i=2; i < N-1; i++) {
        for(int j=0; j < 3; j++) {
            dp[i][0][j] = min(dp[i-1][1][j], dp[i-1][2][j]) + costs[i][0];
            dp[i][1][j] = min(dp[i-1][0][j], dp[i-1][2][j]) + costs[i][1];
            dp[i][2][j] = min(dp[i-1][0][j], dp[i-1][1][j]) + costs[i][2];
        }
    }
    for(int i=0; i < 3; i++) {
        int next1 = (i+1)%3;
        int next2 = (i+2)%3;
        dp[N-1][0][i] = min(dp[N-2][1][i], dp[N-2][2][i]) + costs[N-1][0];
        dp[N-1][1][i] = min(dp[N-2][0][i], dp[N-2][2][i]) + costs[N-1][1];
        dp[N-1][2][i] = min(dp[N-2][0][i], dp[N-2][1][i]) + costs[N-1][2];
        dp[N-1][i][i] = INF;
    }

    int ans = INF;
    for(int i=0; i < 3; i++) {
        for(int j=0; j < 3; j++) {
            if(dp[N-1][i][j] < ans) {
                ans = dp[N-1][i][j];
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int n=0; n < N; n++) {
        cin >> costs[n][0] >> costs[n][1] >> costs[n][2];
    }

    cout << get_min_cost() << '\n';
}