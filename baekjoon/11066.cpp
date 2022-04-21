#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int preSum[501] = {0};
int dp[501][501] = {0};

int solve(int K) {
    for(int size=1; size < K; size++) {
        for(int left=0; left + size < K; left++) {
            int right = left + size;
            int sum = preSum[right + 1] - preSum[left];
            for(int mid = left; mid < right; mid++) {
                dp[left][right] = min(dp[left][right], dp[left][mid] + dp[mid + 1][right] + sum);
            }
        }
    }

    return dp[0][K - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, K, inp;
    cin >> T;
    while(T) {
        cin >> K;
        fill(&dp[0][0], &dp[500][501], INT_MAX);

        preSum[0] = 0;
        for(int i=0; i < K; i++) {
            cin >> inp;
            preSum[i + 1] = preSum[i] + inp;
            dp[i][i] = 0;
        }

        int answer = solve(K);
        
        cout << answer << '\n';
        T--;
    }
}