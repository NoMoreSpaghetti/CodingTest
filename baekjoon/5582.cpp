#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1, s2;
    int ans = 0;
    cin >> s1 >> s2;

    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));

    for(int i=1; i <= s1.length(); i++) {
        for(int j=1; j <= s2.length(); j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << '\n';
}