#include <iostream>
#define MAX (16000001)
using namespace std;

int costs[16][16];
int dp[16][1 << 16];
int N;
int full_visited;

int recursive(int last_visited, int visited) {
    if(visited == full_visited) {
        if(costs[last_visited][0] == 0) {
            return MAX;
        } else {
            return costs[last_visited][0];
        }
    } else {
        int& cost = dp[last_visited][visited];
        if(cost >= 0) {
            return cost;
        } else {
            cost = MAX;
            for(int i=1; i < N; i++) {
                int cur_bit = (1 << i);
                if(!(visited & cur_bit)) {
                    if(costs[last_visited][i] != 0) {
                        cost = min(cost, costs[last_visited][i] + recursive(i, visited | cur_bit));
                    }
                }
            }
            return cost;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&dp[0][0], &dp[15][(1<<16)], -1);

    cin >> N;
    full_visited = (1 << N) - 1;
    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            cin >> costs[i][j];
        }
    }

    cout << recursive(0, 1) << '\n';
}