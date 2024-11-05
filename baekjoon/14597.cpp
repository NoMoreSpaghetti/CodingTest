#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int H, W;
    cin >> H >> W;

    vector<vector<int>> B1(H, vector<int>(W, 0));
    vector<vector<int>> B2(H, vector<int>(W, 0));
    vector<vector<int>> scores(H, vector<int>(W, 0));
    vector<vector<int>> dp(H, vector<int>(W, INT32_MAX));

    for(int i=0; i < H; i++) {
        for(int j=0; j < W; j++) {
            cin >> B1[i][j];
        }
    }

    for(int i=0; i < H; i++) {
        for(int j=0; j < W; j++) {
            cin >> B2[i][j];
        }
    }

    int ans = INT32_MAX;

    for(int i=0; i < H; i++) {
        for(int j=0; j < W; j++) {
            scores[i][j] = (B1[i][j] - B2[i][j]) * (B1[i][j] - B2[i][j]);
        }
    }

    for(int i=0; i < W; i++) {
        dp[0][i] = scores[0][i];
    }

    for(int i=1; i < H; i++) {
        for(int j=0; j < W; j++) {
            for(int k=-1; k <= 1; k++) {
                int prev_x = j + k;
                if(prev_x < 0 || prev_x >= W) continue;

                dp[i][j] = min(dp[i][j], dp[i - 1][prev_x]);
            }
            dp[i][j] += scores[i][j];
        }
    }

    for(int i=0; i < W; i++) {
        ans = min(ans, dp[H - 1][i]);
    }

    cout << ans << '\n';

}