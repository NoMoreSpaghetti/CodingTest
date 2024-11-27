#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 왼쪽 위부터 시계방향으로
int dy[6] = {-1, -1, 0, 1, 1, 0};
int dx[6] = {0, 1, 1, 0, -1, -1};

// 1: 시계방향, 2: 반시계방향
void BFS(vector<string>& gears, vector<vector<bool>>& visited, vector<string>& answer, int R, int C, int y, int x) {
    bool is_blocked = false;

    queue<pair<pair<int, int>, char>> q;
    queue<pair<int, int>> history;
    history.push({y, x});
    q.push({{y, x}, '('});
    visited[y][x] = true;

    while(!q.empty()) {
        pair<int, int> cur = q.front().first;
        char direction = q.front().second;
        q.pop();

        answer[cur.first][cur.second] = direction;
        char next_direction = (direction == '(') ? ')' : '(';

        for(int i=0; i < 6; i++) {
            pair<int, int> next = {cur.first + dy[i], cur.second + dx[i]};

            if(next.first < 0 || next.first >= R || next.second < 0 || next.second >= C) continue;
            if(gears[next.first][next.second] == '.') continue;
            
            if(gears[next.first][next.second] == 'I') {
                // 연결된 기어가 활성화되는 기어라면?
                if(next_direction == ')') {
                    is_blocked = true;
                }
            }

            if(visited[next.first][next.second]) {
                // 이미 방문했던 기어에 다시 방문했을 때, 자신과 해당 기어를 포함해서 홀수개로 방문하게 되면 block
                // 회전 방향이 같으면 block으로 처리하는게 가장 간단

                if(answer[next.first][next.second] == direction) {
                    is_blocked = true;
                }
                continue;
            }

            visited[next.first][next.second] = true;
            q.push({next, next_direction});
            history.push(next);
        }
    }

    if(is_blocked) {
        while(!history.empty()) {
            pair<int, int> cur = history.front();
            history.pop();

            answer[cur.first][cur.second] = 'B';
        }
    }
}

void BFS_all(vector<string>& gears, int R, int C) {
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    vector<string> answer(gears);

    for(int i=0; i < R; i++) {
        for(int j=0; j < C; j++) {
            if(gears[i][j] == 'I' && visited[i][j] == false) {
                BFS(gears, visited, answer, R, C, i, j);
            }
        }
    }

    for(int i=0; i < R; i++) {
        for(int j=0; j < C; j++) {
            if(answer[i][j] == '*') {
                cout << 'F';
            } else {
                cout << answer[i][j];
            }
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int R, C;

    cin >> R >> C;
    while(R != 0) {
        cout << '\n';

        vector<string> gears(R, "");
        for(int i=0; i < R; i++) {
            cin >> gears[i];
        }

        BFS_all(gears, R, C);

        cin >> R >> C;
    }
}
