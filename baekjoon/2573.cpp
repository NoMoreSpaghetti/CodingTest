#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

vector<vector<int>> glacier;
vector<vector<int>> melting_height;
vector<vector<bool>> visited;

bool check_valid_point(const pair<int, int>& p) {
    return !(p.first < 0 || p.first >= N || p.second < 0 || p.second >= M);
}

void bfs(int start_y, int start_x) {
    queue<pair<int, int>> q;
    q.push({start_y, start_x});
    visited[start_y][start_x] = true;

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for(int i=0; i < 4; i++) {
            pair<int, int> next = {cur.first + dy[i], cur.second + dx[i]};
            if(!check_valid_point(next)) {
                continue;
            }
            if(glacier[next.first][next.second] == 0) {
                melting_height[cur.first][cur.second]++;
            } else if(!visited[next.first][next.second]) {
                visited[next.first][next.second] = true;
                q.push(next);
            }
        }
    }
}

void one_year_later() {
    // 빙산 녹이기!!
    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            glacier[i][j] -= melting_height[i][j];
            glacier[i][j] = max(glacier[i][j], 0);
        }
    }
    melting_height = vector<vector<int>>(N, vector<int>(M, 0));
}

int count_glaciers() {
    int num_bfs = 0;
    visited = vector<vector<bool>>(N, vector<bool>(M, false));

    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            if(visited[i][j] == false && glacier[i][j] > 0) {
                bfs(i, j);
                num_bfs++;
            }
        }
    }

    return num_bfs;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    glacier = vector<vector<int>>(N, vector<int>(M, 0));
    melting_height = vector<vector<int>>(N, vector<int>(M, 0));
    visited = vector<vector<bool>>(N, vector<bool>(M, true));

    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            cin >> glacier[i][j];
        }
    }

    int ans = 0;
    count_glaciers();

    while(true) {
        ans++;
        one_year_later();
        int num_glaciers = count_glaciers();

        if(num_glaciers >= 2) {
            cout << ans << '\n';
            return 0;
        } else if(num_glaciers == 0) {
            break;
        }
    }

    cout << 0 << '\n';
    return 0;
}