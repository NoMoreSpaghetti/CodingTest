#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> coins;
int dp[100001] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    int inp;
    for(int i=0; i < n; i++) {
        cin >> inp;
        coins.push_back(inp);
    }

    for(int i=0; i < n; i++) {
        if(coins[i] <= k) {
            dp[coins[i]]++;
        }
        for(int j=coins[i] + 1; j <= k; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    cout << dp[k] << '\n';

}