#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
bool visited[10001] = {0};

int bfs(vector<vector<int>>& computers, int n) {
    queue<int> q;
    fill(visited, visited + N + 1, false);
    q.push(n);
    visited[n] = true;

    int num = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        num++;

        for(int i=0; i < computers[cur].size(); i++) {
            int& next = computers[cur][i];
            if(!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }

    return num;
}

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) {
        return a.first < b.first;
    } else {
        return a.second >= b.second;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B;
    cin >> N >> M;

    vector<vector<int>> computers(N + 1, vector<int>());
    
    for(int i=0; i < M; i++) {
        cin >> A >> B;
        computers[B].push_back(A);
    }

    vector<pair<int, int>> cnt;
    for(int i=1; i <= N; i++) {
        cnt.push_back({i, bfs(computers, i)});
    }
    sort(cnt.begin(), cnt.end(), compare);

    cout << cnt[0].first << ' ';
    for(int i=1; i < cnt.size() && cnt[i].second == cnt[0].second; i++) {
        cout << cnt[i].first << ' ';
    }
}