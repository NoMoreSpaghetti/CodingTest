#include <iostream>
#include <vector>
using namespace std;

int T, W;
vector<int> trees;
int opposite[] = {0, 2, 1};
int dp[2][31][1000];

int recursive(int idx, int cur, int remain_moves) {
    if(idx == T) {
        return 0;
    } else if(remain_moves < 0) {
        return 0;
    } else {
        int& ret = dp[cur - 1][remain_moves][idx];
        if(ret != -1) {
            return ret;
        } else {
            ret = 0;
            if(trees[idx] == cur) {
                ret = 1;
            }
            return ret += max(recursive(idx + 1, cur, remain_moves), recursive(idx + 1, opposite[cur], remain_moves - 1));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&dp[0][0][0], &dp[1][30][1000], -1);
    int inp;
    cin >> T >> W;

    for(int i=0; i < T; i++) {
        cin >> inp;
        trees.push_back(inp);
    }

    cout << max(recursive(0, 1, W), recursive(0, 2, W - 1)) << '\n';
}