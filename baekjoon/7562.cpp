#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int d_x[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int d_y[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void bfs(const int& I, const int& start_x, const int& start_y, const int& dest_x, const int& dest_y) {
    queue<pair<pair<int, int>, int>> q;
    vector<vector<bool>> visited(I, vector<bool>(I, false));
    visited[start_x][start_y] = true;
    q.push({{start_x, start_y}, 0});

    while(!q.empty()) {
        pair<int, int> cur_pos = q.front().first;
        int num = q.front().second;
        q.pop();
        for(int i=0; i < 8; i++) {
            pair<int, int> new_pos = {cur_pos.first + d_x[i], cur_pos.second + d_y[i]};
            if(new_pos.first >= 0 && new_pos.first < I && new_pos.second >= 0 && new_pos.second < I) {
                if(new_pos.first == dest_x && new_pos.second == dest_y) {
                    cout << num + 1 << '\n';
                    return;
                }
                if(!visited[new_pos.first][new_pos.second]) {
                    q.push({new_pos, num + 1});
                    visited[new_pos.first][new_pos.second] = true;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, I, start_x, start_y, dest_x, dest_y;
    cin >> t;
    while(t--) {
        cin >> I >> start_x >> start_y >> dest_x >> dest_y;
        if(start_x == dest_x && start_y == dest_y) {
            cout << 0 << '\n';
        } else {
            bfs(I, start_x, start_y, dest_x, dest_y);
        }
    }
}