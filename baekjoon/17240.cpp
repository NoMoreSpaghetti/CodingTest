#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int N;
vector<vector<int>> candidates;
vector<vector<int>> dp;
set<int> selected_idx_set;

int recursive(int role_bit, int idx) {
    if(idx == N) {
        if(role_bit == ((1 << 5) - 1)) return 0;
        return INT32_MIN;
    }

    if(dp[role_bit][idx] != -1) {
        return dp[role_bit][idx];
    }

    int max_val = 0;
    for(int i=0; i < 5; i++) {
        if((role_bit & (1 << i)) > 0) continue;

        max_val = max(max_val, recursive(role_bit | (1 << i), idx + 1) + candidates[i][idx]);
    }

    max_val = max(max_val, recursive(role_bit, idx + 1));

    return dp[role_bit][idx] = max_val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    candidates = vector<vector<int>>(5, vector<int>(N, 0));
    // idx 이후의 사람들이 max가 되는 경우를 저장해 놓기
    dp = vector<vector<int>>(32, vector<int>(N, -1));

    for(int i=0; i < N; i++) {
        for(int j=0; j < 5; j++) {
            cin >> candidates[j][i];
        }
    }

    int ans = recursive(0, 0);
    cout << ans << '\n';
}