#include <iostream>
#include <vector>
#define DIV_VAL (1000000009)
using namespace std;

vector<int> dp;

int recursive(int n) {
    if(dp[n] != -1) {
        return dp[n];
    }

    dp[n] = (recursive(n - 1) + recursive(n - 2)) % DIV_VAL;
    dp[n] += recursive(n - 3);
    dp[n] %= DIV_VAL;
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, n;
    dp = vector<int>(1000001, -1);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 7;

    cin >> T;

    while(T--) {
        cin >> n;
        cout << recursive(n) << '\n';
    }
}