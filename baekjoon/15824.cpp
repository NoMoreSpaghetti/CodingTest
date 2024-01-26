#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define DIV_NUM (1000000007)
using namespace std;

int N;
vector<int> menus;
vector<int> dp;

long long pow(long long n) {
    if(dp[n] != -1) {
        return dp[n];
    }
    // 짝수인 경우
    if(n & 1 == 0) {
        long long pow_val = pow(n >> 1);
        return dp[n] = (pow_val * pow_val) % DIV_NUM;
    }
    // 홀수인 경우
    return dp[n] = (pow(n - 1) * 2) % DIV_NUM;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int inp;
    cin >> N;
    dp = vector<int>(N, -1);
    dp[0] = 1;
    dp[1] = 2;

    for(int i=0; i < N; i++) {
        cin >> inp;
        menus.push_back(inp);
    }

    sort(menus.begin(), menus.end());

    long long max_val_sum = 0;
    long long min_val_sum = 0;
    long long ans = 0;
    for(int i=N - 1; i >= 0; i--) {
        min_val_sum += menus[N - 1 - i] * pow(i);
        max_val_sum += menus[i] * pow(i);
        min_val_sum %= DIV_NUM;
        max_val_sum %= DIV_NUM;
    }

    ans = (max_val_sum - min_val_sum + DIV_NUM) % DIV_NUM;

    cout << ans << '\n';
}