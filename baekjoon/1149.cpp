#include <iostream>
using namespace std;

int N;
int cost[1000][3];
int dp[1000][3];

int get_mininum_cost() {
    for(int i=0; i < 3; i++) {
        dp[0][i] = cost[0][i];
    }

    for(int n=1; n < N; n++) {
        for(int i=0; i < 3; i++) {
            dp[n][i] = cost[n][i] + min(dp[n-1][(i+1) % 3], dp[n-1][(i+2) % 3]);
        }
    }

    return min(min(dp[N-1][0], dp[N-1][1]), dp[N-1][2]);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i=0; i < N; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    cout << get_mininum_cost() << '\n';
}