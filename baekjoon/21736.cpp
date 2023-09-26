#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
char campus[600][600];
int d_y[4] = {-1, 0, 1, 0};
int d_x[4] = {0, -1, 0, 1};

int bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});

    int num_p = 0;
    bool visited[600][600] = {0};

    visited[y][x] = true;

    while(!q.empty()) {
        pair<int, int> cur_pos = q.front();
        q.pop();

        for(int i=0; i < 4; i++) {
            pair<int, int> new_pos = {cur_pos.first + d_y[i], cur_pos.second + d_x[i]};
            if(visited[new_pos.first][new_pos.second] || new_pos.first < 0 || new_pos.first >= N || new_pos.second < 0 || new_pos.second >= M) {
                continue;
            }

            if(campus[new_pos.first][new_pos.second] == 'X') {
                continue;
            } else if(campus[new_pos.first][new_pos.second] == 'P') {
                num_p++;
            }

            visited[new_pos.first][new_pos.second] = true;
            q.push(new_pos);
        }
    }

    return num_p;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    int start_y = 0, start_x = 0;
    
    for(int n=0; n < N; n++) {
        for(int m=0; m < M; m++) {
            cin >> campus[n][m];
            if(campus[n][m] == 'I') {
                start_y = n;
                start_x = m;
            }
        }
    }

    int ans = bfs(start_y, start_x);
    if(ans == 0) {
        cout << "TT" << '\n';
    } else {
        cout << ans << '\n';
    }
}