#include <iostream>
using namespace std;

int INF = 400001;
int dp[2][5][5] = {0};
int costs[5][5] = {
    {1, 2, 2, 2, 2},
    {2, 1, 3, 4, 3},
    {2, 3, 1, 3, 4},
    {2, 4, 3, 1, 3},
    {2, 3, 4, 3, 1}
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&dp[0][0][0], &dp[1][4][5], INF);

    int prev_step, next_step, ary_size=0;
    cin >> next_step;
    dp[0][0][next_step] = 2;
    dp[0][next_step][0] = 2;
    ary_size++;
    prev_step = next_step;
    cin >> next_step;
    
    int idx1 = 1;
    int idx2 = 0;
    while(next_step) {
        int temp = idx1;
        idx1 = idx2;
        idx2 = temp;
        fill(&dp[idx2][0][0], &dp[idx2][4][5], INF);
        for(int i=0; i < 5; i++) {
            for(int j=0; j < 5; j++) {
                dp[idx2][i][next_step] = min(dp[idx2][i][next_step], dp[idx1][i][j] + costs[j][next_step]);
                dp[idx2][next_step][i] = min(dp[idx2][next_step][i], dp[idx1][j][i] + costs[j][next_step]);
            }
        }

        ary_size++;
        prev_step = next_step;
        cin >> next_step;
    }

    int ans = INF;
    for(int i=0; i < 5; i++) {
        ans = min(ans, dp[idx2][i][prev_step]);
        ans = min(ans, dp[idx2][prev_step][i]);
    }

    cout << ans << '\n';
}