#include <iostream>
#include <cmath>
using namespace std;

int dp[50001] = {0,};

int main() {
    int inp;
    cin >> inp;

    dp[1] = 1;

    for(int i=2; i <= inp; i++) {
        dp[i] = 5;
        for(int j=1; j * j <= i; j++) {
            dp[i] = min(dp[i - j * j], dp[i]);
        }
        dp[i] += 1;
    }

    cout << dp[inp] << '\n';
}