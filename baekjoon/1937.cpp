#include <iostream>
#include <vector>
using namespace std;

int n;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

vector<vector<int>> forest;
vector<vector<int>> dp;

void dfs(pair<int, int> cur) {
    if(dp[cur.first][cur.second] != 1) {
        return;
    }

    for(int i=0; i < 4; i++) {
        pair<int, int> next_pos = {cur.first + dy[i], cur.second + dx[i]};
        if(next_pos.first >= 0 && next_pos.first < n && next_pos.second >= 0 && next_pos.second < n) {
            if(forest[next_pos.first][next_pos.second] < forest[cur.first][cur.second]) {
                if(dp[next_pos.first][next_pos.second] == 1) {
                    dfs(next_pos);
                }
                dp[cur.first][cur.second] = max(dp[cur.first][cur.second], 1 + dp[next_pos.first][next_pos.second]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    forest = vector<vector<int>>(n, vector<int>(n, 0));
    dp = vector<vector<int>>(n, vector<int>(n, 1));
    // visited = vector<vector<bool>>(n, vector<bool>(n, false));

    for(int i=0; i < n; i++) {
        for(int j=0; j < n; j++) {
            cin >> forest[i][j];
        }
    }

    int answer = 0;
    for(int i=0; i < n; i++) {
        for(int j=0; j < n; j++) {
            if(dp[i][j] == 1) {
                dfs({i, j});
            }
            answer = max(answer, dp[i][j]);
        }
    }

    cout << answer << '\n';
}