#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> cards = vector<int>(N + 1, 0);
    vector<int> dp = vector<int>(N + 1, 0);

    for(int i=1; i <= N; i++) {
        cin >> cards[i];
    }

    for(int i=1; i <= N; i++) {
        dp[i] = cards[i];
        for(int j=1; j < i; j++) {
            dp[i] = max(dp[i], dp[j] + dp[i - j]);
        }
    }

    cout << dp[N] << '\n';
}