#include <iostream>
#include <vector>
using namespace std;

int N, Q;
vector<vector<int>> board;
vector<vector<int>> cumulative_sum;

int GetSum(pair<int, int> a, pair<int, int> b) {
    return cumulative_sum[b.first][b.second] - cumulative_sum[b.first][a.second - 1] - cumulative_sum[a.first - 1][b.second] + cumulative_sum[a.first - 1][a.second - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    board = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
    cumulative_sum = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));

    for(int i=1; i <= N; i++) {
        for(int j=1; j <= N; j++) {
            cin >> board[i][j];
            cumulative_sum[i][j] = board[i][j] + cumulative_sum[i - 1][j] + cumulative_sum[i][j - 1] - cumulative_sum[i - 1][j - 1];
        }
    }

    cin >> Q;

    int r1, c1, r2, c2;
    for(int i=0; i < Q; i++) {
        cin >> r1 >> c1 >> r2 >> c2;
        int ans = -GetSum({r1, c1}, {r2, c2}) + GetSum({r1 + 1, c1 + 1}, {r2 - 1, c2 - 1}) * 2;
        cout << ans << '\n';
    }
}