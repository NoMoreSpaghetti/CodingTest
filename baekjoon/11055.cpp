#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    vector<int> vec(N, 0);

    for(int i=0; i < N; i++) {
        cin >> vec[i];
    }

    vector<int> dp(vec);
    int ans = dp[0];

    for(int i=1; i < N; i++) {
        for(int j=i - 1; j >= 0; j--) {
            if(vec[j] < vec[i]) {
                dp[i] = max(dp[i], dp[j] + vec[i]);
                ans = max(ans, dp[i]);
            }
        }
    }

    cout << ans << '\n';
}