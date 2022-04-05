#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, m;
vector<vector<char>> vec;
bool visited[50][50] = {0};
int directions[2][2] = {{1, 0}, {0, 1}};

bool check_valid(pair<int, int>& p) {
    if(p.first >= 0 && p.first < n && p.second >= 0 && p.second < m) {
        return true;
    }
    return false;
}

void dfs(pair<int, int> start, int direction) {
    stack<pair<int, int>> s;
    s.push(start);
    visited[start.first][start.second] = true;
    char shape = vec[start.first][start.second];

    while(!s.empty()) {
        pair<int, int> cur = s.top();
        s.pop();

        visited[cur.first][cur.second] = true;

        pair<int, int> next = {cur.first + directions[direction][0], cur.second + directions[direction][1]};
        if(check_valid(next) && vec[next.first][next.second] == shape) {
            s.push(next);
        }
    }
}

int dfs_all() {
    int num = 0;
    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++) {
            if(visited[i][j] == false) {
                if(vec[i][j] == '-') {
                    dfs({i, j}, 1);
                } else {
                    dfs({i, j}, 0);
                }
                num++;
            }
        }
    }
    return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    vec = vector<vector<char>>(n, vector<char>(m, 0));

    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++) {
            cin >> vec[i][j];
        }
    }

    cout << dfs_all() << '\n';
}