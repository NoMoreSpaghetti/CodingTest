#include <iostream>
using namespace std;

int N, M;
int board[1025][1025];
int dp[1025][1025];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x1, y1, x2, y2;

    cin >> N >> M;

    for(int i=1; i <= N; i++) {
        for(int j=1; j <= N; j++) {
            cin >> board[i][j];
        }
    }

    for(int i=0; i <= N; i++) {
        dp[0][i] = 0;
        dp[i][0] = 0;
    }

    for(int i=1; i <= N; i++) {
        dp[1][i] = dp[1][i-1] + board[1][i];
        dp[i][1] = dp[i-1][1] + board[i][1];
    }

    for(int i=2; i <= N; i++) {
        for(int j=2; j <= N; j++) {
            dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + board[i][j];
        }
    }

    for(int m=0; m < M; m++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1] << '\n';
    }
}