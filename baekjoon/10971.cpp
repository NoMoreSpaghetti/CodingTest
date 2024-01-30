#include <iostream>
#include <vector>
using namespace std;

int N;
int START_NODE = 0;

vector<vector<int>> W;
vector<vector<int>> dp;

int recursive_travel(int last_node_idx, int visited) {
    // 모든 노드를 방문한 경우
    // 맨 처음 노드로 다시 돌아가는 비용 계산하기
    // 시작 노드는 0번 노드로 
    if(visited == (1 << N) - 1) {
        if(W[last_node_idx][START_NODE] != 0) {
            return dp[last_node_idx][visited] = W[last_node_idx][START_NODE];
        }
        return INT32_MAX;
    }

    int& cost = dp[last_node_idx][visited];

    // cost가 MAX값인 경우는
    // 경로가 없는 경우
    if(cost != INT32_MAX) {
        return cost;
    }

    // 다음 노드의 최소 비용 계산
    for(int i=0; i < N; i++) {
        int cur_bit = (1 << i);
        if(last_node_idx == i || visited & cur_bit || W[last_node_idx][i] == 0) {
            continue;
        }

        int next_cost = recursive_travel(i, visited | cur_bit);
        if(next_cost != INT32_MAX) {
            dp[last_node_idx][visited] = min(dp[last_node_idx][visited], next_cost + W[last_node_idx][i]);
        }
    }
    return dp[last_node_idx][visited];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    W = vector<vector<int>>(N, vector<int>(N, 0));
    dp = vector<vector<int>>(N, vector<int>(1 << N, INT32_MAX));

    int inp;
    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            cin >> inp;
            W[i][j] = inp;
        }
    }

    // 순회이므로 0에서 시작하는 비용 하나만 구해도 정답
    cout << recursive_travel(START_NODE, 1) << '\n';
}