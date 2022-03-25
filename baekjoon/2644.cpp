#include <iostream>
#include <queue>
using namespace std;

int n, m;
bool graph[101][101] = {0};
bool visited[101] = {0};

int bfs(int n1, int n2) {
    queue<pair<int, int>> q;
    q.push({0, n1});
    int ans = -1;

    visited[n1] = true;
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        if(cur.second == n2) {
            ans = cur.first;
            break;
        }
        for(int i=1; i <= n; i++) {
            if(graph[cur.second][i] && !visited[i]) {
                q.push({cur.first + 1, i});
                visited[i] = true;
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int y, x, num1, num2;
    
    cin >> n >> num1 >> num2 >> m;
    for(int i=0; i < m; i++) {
        cin >> y >> x;
        graph[y][x] = true;
        graph[x][y] = true;
    }

    cout << bfs(num1, num2) << '\n';
}