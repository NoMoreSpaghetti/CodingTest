#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[3] = {0, 1, -1};
int dx[3] = {-1, -1, -1};

vector<vector<char>> board;
vector<vector<int>> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    board = vector<vector<char>>(N, vector<char>(M, ' '));
    dp = vector<vector<int>>(N, vector<int>(M, -1));

    int start_y;
    int start_x;

    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'R') {
                start_y = i;
                start_x = j;
            }
        }
    }

    dp[start_y][start_x] = 0;
    int ans = -1;

    for(int j=start_x + 1; j < M; j++) {
        for(int i=0; i < N; i++) {
            // 현재 위치가 벽이면 다음 위치 탐색
            if(board[i][j] == '#') continue;

            for(int k=0; k < 3; k++) {
                int prev_y = i + dy[k];
                int prev_x = j + dx[k];

                // 이전 위치 중 범위를 벗어나거나 방문한 적이 없으면 다음 이전 위치 탐색
                if(prev_y < 0 || prev_y >= N || dp[prev_y][prev_x] == -1) continue;

                dp[i][j] = max(dp[i][j], dp[prev_y][prev_x]);
            }

            // 현재 위치에 당근이 있으면 개수 추가
            if(dp[i][j] != -1 && board[i][j] == 'C') dp[i][j]++;
            else if(board[i][j] == 'O') ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << '\n';
}