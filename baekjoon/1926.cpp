#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, m;
vector<vector<int>> pic;
vector<vector<bool>> visited;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

int dfs(int start_y, int start_x) {
    stack<pair<int, int>> s;
    int size = 1;

    s.push({start_y, start_x});
    visited[start_y][start_x] = true;
    while(!s.empty()) {
        pair<int, int> cur_pos = s.top();
        s.pop();

        for(int i=0; i < 4; i++) {
            pair<int, int> next_pos = {cur_pos.first + dy[i], cur_pos.second + dx[i]};
            if(next_pos.first >= 0 && next_pos.first < n && next_pos.second >= 0 && next_pos.second < m) {
                if(pic[next_pos.first][next_pos.second] == 1 && !visited[next_pos.first][next_pos.second]) {
                    visited[next_pos.first][next_pos.second] = true;
                    s.push(next_pos);
                    size++;
                }
            }
        }
    }

    return size;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    pic = vector<vector<int>>(n, vector<int>(m, 0));
    visited = vector<vector<bool>>(n, vector<bool>(m, false));

    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++) {
            cin >> pic[i][j];
        }
    }

    int num_pics = 0;
    int max_size = 0;

    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++) {
            if(pic[i][j] == 1 && !visited[i][j]) {
                int size = dfs(i, j);
                max_size = max(max_size, size);
                num_pics++;
            }
        }
    }

    cout << num_pics << '\n' << max_size << '\n';
}