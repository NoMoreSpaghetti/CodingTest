#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> dp(N, vector<int>(10, 0));

    for(int i=0; i < 10; i++) {
        dp[0][i] = 1;
    }


    for(int i=1; i < N; i++) {
        for(int j=0; j < 10; j++) {
            for(int k=j; k < 10; k++) {
                dp[i][j] += dp[i - 1][k];
            }
            dp[i][j] %= 10007;
        }
    }

    int answer = 0;
    for(int i=0; i < 10; i++) {
        answer += dp[N - 1][i];
    }
    answer %= 10007;
    cout << answer << '\n';
}