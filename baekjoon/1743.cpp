#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N, M, K;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

vector<vector<char>> board;
vector<vector<bool>> visited;

int dfs(pair<int, int> cur, int size) {
    for(int i=0; i < 4; i++) {
        pair<int, int> next = {cur.first + dy[i], cur.second + dx[i]};
        if(next.first >= 0 && next.first < N && next.second >= 0 && next.second < M) {
            if(board[next.first][next.second] == '#' && !visited[next.first][next.second]) {
                visited[next.first][next.second] = true;
                size = dfs(next, size + 1);
            }
        }
    }

    return size;
}

int run_dfs() {
    visited = vector<vector<bool>>(N, vector<bool>(M, false));
    int ans = 0;

    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            if(board[i][j] == '#' && visited[i][j] == false) {
                ans = max(ans, dfs({i, j}, 0));
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    board = vector<vector<char>>(N, vector<char>(M, '.'));

    int y, x;

    for(int i=0; i < K; i++) {
        cin >> y >> x;
        board[y - 1][x - 1] = '#';
    }

    cout << run_dfs() << '\n';
}