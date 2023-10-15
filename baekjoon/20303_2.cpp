#include <iostream>
#include <vector>
#include <queue>
#define MAX(A, B) ((A) > (B) ? (A) : (B))
using namespace std;

vector<int> candies;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> group_size;
vector<int> group_candies;
int num_groups = 0;

void bfs(int i) {
    int cur, num_friends = 0, num_candies = 0;
    queue<int> q;
    q.push(i);
    visited[i] = true;

    while(!q.empty()) {
        cur = q.front();
        q.pop();
        num_friends++;
        num_candies += candies[cur];
        for(auto& next : graph[cur]) {
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    group_size.push_back(num_friends);
    group_candies.push_back(num_candies);
    num_groups++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K, a, b;
    cin >> N >> M >> K;

    candies = vector<int>(N + 1, 0);
    graph = vector<vector<int>>(N + 1, vector<int>());
    visited = vector<bool>(N + 1, false);

    for(int i=1; i <= N; i++) {
        cin >> candies[i];
    }

    for(int i=0; i < M; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=1; i <= N; i++) {
        if(!visited[i]) {
            bfs(i);
        }
    }

    // 사람 수에 따른 최대 개수
    vector<int> dp(K, 0);
    for(int i=0; i < num_groups; i++) {
        for(int j=K-1; j >= group_size[i]; j--) {
            dp[j] = MAX(dp[j], dp[j - group_size[i]] + group_candies[i]);
        }
    }

    cout << dp[K - 1] << '\n';
}