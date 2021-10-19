#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[1000];
int dp[1000][2];

int get_length() {
    for(int i=1; i < N; i++) {
        for(int j=i-1; j >= 0; j--) {
            if(A[i] > A[j]) {
                if(dp[j][0] >= dp[i][0]) {
                    dp[i][0] = dp[j][0] + 1;
                }
            }
        }
    }

    for(int i=N-2; i >= 0; i--) {
        for(int j=i+1; j < N; j++) {
            if(A[i] > A[j]) {
                if(dp[j][1] >= dp[i][1]) {
                    dp[i][1] = dp[j][1] + 1;
                }
            }
        }
    }

    int max_len = 0;
    for(int i=0; i < N; i++) {
        if(dp[i][0] + dp[i][1] > max_len) {
            max_len = dp[i][0] + dp[i][1];
        }
    }

    if(max_len == 1) {
        return max_len;
    }
    return max_len - 1;
}

int main() {
    cin >> N;

    for(int n=0; n < N; n++) {
        cin >> A[n];
    }

    fill(&dp[0][0], &dp[999][2], 1);

    cout << get_length() << '\n';

}
