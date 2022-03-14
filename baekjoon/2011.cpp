#include <iostream>
using namespace std;

string s;
int dp[5000][2] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;

    if(s[0] == '0') {
        cout << 0 << '\n';
    } else {
        dp[0][0] = 1;
        if((s[0] - '0') * 10 + (s[1] - '0') <= 26) {
            dp[1][1] = 1;
        }

        if(s[1] != '0') {
            dp[1][0] = 1;
        }

        for(int i=2; i < s.length(); i++) {
            int prev_num = s[i - 1] - '0';
            int cur_num = s[i] - '0';
            if(cur_num != 0) {
                dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % 1000000;
            }
            if(prev_num != 0 && prev_num * 10 + cur_num <= 26) {
                dp[i][1] = (dp[i - 2][0] + dp[i - 2][1]) % 1000000;
            }
        }

        cout << (dp[s.length() - 1][0] + dp[s.length() - 1][1]) % 1000000 << '\n';
    }
}