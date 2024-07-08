#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C, N;
vector<pair<int, int>> rules;
vector<vector<int>> board;

int solution() {
    queue<pair<int, pair<int, int>>> q;
    vector<vector<bool>> visited(R, vector<bool>(C, false));

    for(int i=0; i < C; i++) {
        if(board[0][i] == 1) {
            visited[0][i] = true;
            q.push({0, {0, i}});
        }
    }

    while(!q.empty()) {
        int cur_count = q.front().first;
        pair<int, int> cur = q.front().second;
        q.pop();

        for(int i=0; i < N; i++) {
            pair<int, int> next = {cur.first + rules[i].first, cur.second + rules[i].second};
            if(next.first >= 0 && next.first < R && next.second >= 0 && next.second < C && board[next.first][next.second] == 1 && visited[next.first][next.second] == false) {
                if(next.first == R - 1) {
                    return cur_count + 1;
                }
                q.push({cur_count + 1, next});
                visited[next.first][next.second] = true;
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    board = vector<vector<int>>(R, vector<int>(C, 0));

    for(int i=0; i < R; i++) {
        for(int j=0; j < C; j++) {
            cin >> board[i][j];
        }
    }

    cin >> N;
    rules = vector<pair<int, int>>(N, {0, 0});

    for(int i=0; i < N; i++) {
        cin >> rules[i].first >> rules[i].second;
    }

    cout << solution() << '\n';
}