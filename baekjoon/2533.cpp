#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<vector<int>> tree;
vector<vector<int>> dp;
vector<bool> visited;

void calc(int cur) {
    dp[cur][0] = 1;

    for(auto& child : tree[cur]) {
        // cur이 얼리 아답터인 경우
        // 자식이 얼리 아답터일 필요 없음
        dp[cur][0] += min(dp[child][0], dp[child][1]);
        // cur이 얼리 아답터가 아닌 경우
        // 모든 자식이 얼리 아답터
        dp[cur][1] += dp[child][0];
        // 부모의 dp값은 0일 테니 더해져도 상관없음
    }
}

void recursive_calc(int cur) {
    visited[cur] = true;
    for(auto& child : tree[cur]) {
        if(visited[child] == false) {
            recursive_calc(child);
        }
    }
    calc(cur);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int u, v, root;
    dp = vector<vector<int>>(N + 1, vector<int>(2, 0));
    tree = vector<vector<int>>(N + 1, vector<int>());
    visited = vector<bool>(N + 1, false);

    cin >> u >> v;
    tree[u].push_back(v);
    root = u;

    for(int i=1; i < N - 1; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    recursive_calc(root);
    cout << min(dp[root][0], dp[root][1]) << '\n';;
}
