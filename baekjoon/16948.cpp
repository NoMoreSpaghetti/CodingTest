#include <iostream>
#include <queue>
using namespace std;

int N, r1, c1, r2, c2;
int dy[] = {-2, -2, 0, 0, 2, 2};
int dx[] = {-1, 1, -2, 2, -1, 1};
bool visited[200][200] = {0};

bool is_on_board(int y, int x) {
    if(y >= 0 && y < N && x >= 0 && x < N) {
        return true;
    } else {
        return false;
    }
}

int bfs(int sy, int sx) {
    queue<pair<pair<int, int>, int>> q;
    q.push({{sy, sx}, 0});
    visited[sy][sx] = true;
    while(!q.empty()) {
        int cur_y = q.front().first.first;
        int cur_x = q.front().first.second;
        int cur_cnt = q.front().second;
        q.pop();

        if(cur_y == r2 && cur_x == c2) {
            return cur_cnt;
        }

        for(int i=0; i < 6; i++) {
            int next_y = cur_y + dy[i];
            int next_x = cur_x + dx[i];
            int next_cnt = cur_cnt + 1;
            if(is_on_board(next_y, next_x) && !visited[next_y][next_x]) {
                q.push({{next_y, next_x}, next_cnt});
                visited[next_y][next_x] = true;
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> r1 >> c1 >> r2 >> c2;

    cout << bfs(r1, c1) << '\n';
}