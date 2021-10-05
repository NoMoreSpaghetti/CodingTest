#include <iostream>
#include <algorithm>
using namespace std;

int N;
int tri[500][500];
int dp[500][500];

int get_max_score() {
    dp[0][0] = tri[0][0];
    for(int i=1; i < N; i++) {
        dp[i][0] = dp[i-1][0] + tri[i][0];
        dp[i][i] = dp[i-1][i-1] + tri[i][i];
        for(int j=1; j < i; j++) {
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + tri[i][j];
        }
    }

    int max_val = 0;
    for(int i=0; i < N; i++) {
        if(dp[N-1][i] > max_val) {
            max_val = dp[N-1][i];
        }
    }
    
    return max_val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    for(int n=0; n < N; n++) {
        for(int i=0; i < n+1; i++) {
            cin >> tri[n][i];
        }
    }

    cout << get_max_score() << '\n';
}