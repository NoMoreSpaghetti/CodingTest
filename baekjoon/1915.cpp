#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int n, m;
vector<vector<int>> dp;
vector<string> vec;

int find_largest_square() {
    int max_len = 0;

    for(int i=1; i <= n; i++) {
        for(int j=1; j <= m; j++) {
            if(vec[i - 1][j - 1] == '1') {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                max_len = max(max_len, dp[i][j]);
            }
        }   
    }
    return max_len * max_len;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    vec = vector<string>(n, "");
    dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));

    for(int i=0; i < n; i++) {
        cin >> vec[i];
    }

    cout << find_largest_square() << '\n';

    // for(int i=0; i < n; i++) {
    //     for(int j=0; j < m; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
}