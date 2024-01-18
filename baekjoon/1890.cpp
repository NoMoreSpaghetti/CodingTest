#include <iostream>
#include <vector>
using namespace std;

int dy[2] = {1, 0};
int dx[2] = {0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> game_board = vector<vector<int>>(N, vector<int>(N, 0));
    vector<vector<long long>> dp = vector<vector<long long>>(N, vector<long long>(N, 0));
    dp[0][0] = 1;

    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            cin >> game_board[i][j];
        }
    }

    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            if(i == N - 1 && j == N - 1) {
                continue;
            }
            int next_y = i + game_board[i][j];
            int next_x = j + game_board[i][j];
            if(next_y < N) {
                dp[next_y][j] += dp[i][j];
            }
            if(next_x < N) {
                dp[i][next_x] += dp[i][j];
            }
        }
    }

    cout << dp[N - 1][N - 1] << '\n';
}