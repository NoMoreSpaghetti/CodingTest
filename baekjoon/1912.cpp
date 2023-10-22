#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, inp;
    cin >> N;
    vector<int> arr(N, 0);
    vector<int> dp(N, 0);

    for(int i=0; i < N; i++) {
        cin >> inp;
        arr[i] = inp;
    }

    int max = arr[0];
    dp[0] = arr[0];
    for(int i=1; i < N; i++) {
        dp[i] = (dp[i - 1] + arr[i] > arr[i]) ? dp[i - 1] + arr[i] : arr[i];
        max = (max > dp[i]) ? max : dp[i];
    }
    
    cout << max << '\n';
}