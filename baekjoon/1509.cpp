#include <iostream>
#include <string.h>
using namespace std;

string str;
int is_p[2500][2500];
int dp[2501] = {0};

bool is_palindrome(int s, int e) {
    if(e - s <= 0) {
        return true;
    } else if(is_p[s][e] != -1) {
        return is_p[s][e];
    } else {
        is_p[s][e] = is_palindrome(s + 1, e - 1) && (str[s] == str[e]);
        return is_p[s][e];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;

    fill(&is_p[0][0], &is_p[2499][2500], -1);

    for(int i=0; i < str.length(); i++) {
        dp[i + 1] = dp[i] + 1;
        for(int j=0; j < i; j++) {
            if(is_palindrome(j, i)) {
                dp[i + 1] = min(dp[i + 1], dp[j] + 1);
            }
        }
    }

    cout << dp[str.length()] << '\n';
}