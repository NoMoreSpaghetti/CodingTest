#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<char>> board;
vector<vector<bool>> visited;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int dfs(pair<int, int> cur, int cnt, int num_remain_spaces) {
    if(num_remain_spaces == 0) {
        return cnt;
    }
    
    int min_cnt = INT32_MAX;
    for(int i=0; i < 4; i++) {
        pair<int, int> next = {cur.first + dy[i], cur.second + dx[i]};
        int num_moved = 0;
        while(next.first >= 0 && next.first < N && next.second >= 0 && next.second < M &&
        board[next.first][next.second] == '.' && visited[next.first][next.second] == false) {
            num_moved++;
            visited[next.first][next.second] = true;
            next.first += dy[i];
            next.second += dx[i];
        }

        next.first -= dy[i];
        next.second -= dx[i];

        if(num_moved > 0) {
            min_cnt = min(min_cnt, dfs(next, cnt + 1, num_remain_spaces - num_moved));
        }

        while(num_moved--) {
            visited[next.first][next.second] = false;
            next.first -= dy[i];
            next.second -= dx[i];
        }
    }

    return min_cnt;
}

int solution(int num_empty_spaces) {
    int ans = INT32_MAX;
    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            if(board[i][j] == '.') {
                visited[i][j] = true;
                ans = min(ans, dfs({i, j}, 0, num_empty_spaces - 1));
                visited[i][j] = false;
            }
        }
    }

    if(ans == INT32_MAX) {
        return -1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int case_cnt = 1;
    while(cin >> N >> M) {
        board = vector<vector<char>>(N, vector<char>(M, 0));
        visited = vector<vector<bool>>(N, vector<bool>(M, false));

        int num_empty_spaces = 0;

        for(int i=0; i < N; i++) {
            for(int j=0; j < M; j++) {
                cin >> board[i][j];
                if(board[i][j] == '.') {
                    num_empty_spaces++;
                }
            }
        }

        cout << "Case " << case_cnt << ": " << solution(num_empty_spaces) << '\n';
        case_cnt++;
    }
}