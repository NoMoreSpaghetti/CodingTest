#include <iostream>
using namespace std;

int N, M;
long long memory[100];
int cost[100];
long long dp[10001] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    int cost_sum = 0;

    for(int n=0; n < N; n++) {
        cin >> memory[n];
    }
    for(int n=0; n < N; n++) {
        cin >> cost[n];
        cost_sum += cost[n];
    }

    int mem = 0;
    for(int i=0; i < N; i++) {
        // 앱 선택
        for(int j=cost_sum; j >= cost[i]; j--) {
            dp[j] = max(dp[j], dp[j - cost[i]] + memory[i]);
        }
    }

    for(int i=0; i <= cost_sum; i++) {
        if(dp[i] >= M) {
            cout << i << '\n';
            break;
        }
    }
}