#include <iostream>
#include <vector>
#define INT_MIN (-10000000)
using namespace std;

int N, S, T;
vector<int> board;
vector<vector<int>> dp;


int solution(int cur, int remain_T) {
    if(cur < 0) {
        return 0;
    }
    if(remain_T < 0) {
        return INT_MIN;
    }

    if(dp[cur][remain_T] == INT_MIN) {
        for(int i=1; i <= S; i++) {
            dp[cur][remain_T] = max(dp[cur][remain_T], solution(cur - i, remain_T - 1) + board[cur]);
        }
    }

    return dp[cur][remain_T];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    while(N != 0) {
        cin >> S >> T;
        board = vector<int>(N + 1, 0);
        dp = vector<vector<int>>(N + 1, vector<int>(T, INT_MIN));
        
        for(int i=0; i < N; i++) {
            cin >> board[i];
        }

        cout << solution(N, T - 1) << '\n';

        cin >> N;
    }
}