#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfs(vector<vector<int>>& circles, vector<bool>& visited, int start) {
    // 빨강, 검정으로 번갈아가며 색칠. 빨강: 1, 검정: -1
    vector<int> colors(circles.size(), 0);
    queue<int> q;
    q.push(start);
    colors[start] = 1;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(const auto& next: circles[cur]) {
            if(!visited[next]) {
                visited[next] = true;
                colors[next] = -colors[cur];
                q.push(next);
            } else {
                if(colors[next] != -colors[cur]) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool run_bfs(vector<vector<int>> circles, int n) {
    vector<bool> visited(n, false);

    for(int i=1; i <= n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            bool valid = bfs(circles, visited, i);
            if(!valid) {
                return valid;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, n, m, x, y;
    cin >> T;

    // 2가지 색상으로 다 못칠하는 경우:
    // 홀수개의 동그라미로 구성된 cycle이 있는 경우
    while(T--) {
        cin >> n >> m;
        vector<vector<int>> circles(n + 1, vector<int>());
        for(int i=0; i < m; i++) {
            cin >> x >> y;
            circles[x].push_back(y);
            circles[y].push_back(x);
        }

        bool valid = run_bfs(circles, n);
        if(valid) {
            cout << "possible" << '\n';
        } else {
            cout << "impossible" << '\n';
        }
    }

}