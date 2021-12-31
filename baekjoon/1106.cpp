#include <iostream>
#define MAX (100001);
using namespace std;

int C, N;
int costs[20];
int customers[20];
int dp[1101][20];

int recursive(int idx, int n) {
    if(n <= 0) {
        return 0;
    } else if(idx == N) {
        return MAX;
    } else {
        int& ret = dp[n][idx];
        if(ret != -1) {
            return ret;
        } else {
            ret = recursive(idx, n - customers[idx]) + costs[idx];
            ret = min(ret, recursive(idx + 1, n));
        }
        return ret;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&dp[0][0], &dp[1100][20], -1);
    
    cin >> C >> N;
    for(int i=0; i < N; i++) {
        cin >> costs[i] >> customers[i];
    }

    cout << recursive(0, C) << '\n';
}