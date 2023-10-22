#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_NUM 20000
using namespace std;

vector<int> dp;
vector<int> coins;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, inp;
    cin >> n >> k;

    dp = vector<int>(k + 1, MAX_NUM);
    dp[0] = 0;
    
    for(int i=0; i < n; i++) {
        cin >> inp;
        coins.push_back(inp);
        dp[inp] = 1;
    }

    for(auto& coin : coins) {
        for(int j=1; j <= k; j++) {
            if(j > coin) {
                dp[j] = min(dp[j], dp[j - coin] + 1);
            }
        }
    }

    if(dp[k] == MAX_NUM) {
        cout << -1 << '\n';
    } else {
        cout << dp[k] << '\n';
    }
}