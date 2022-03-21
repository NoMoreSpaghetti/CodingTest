// 참고: https://steady-coding.tistory.com/322
#include <iostream>
#include <cmath>
using namespace std;

int dp[20001] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 6;
    dp[4] = 4;

    for(int i=5; i <= N; i++) {
        if(i % 5 == 0) {
            int q = i / 5;
            // 2^A * A!값이 Unit Digit
            dp[i] = ((int)pow(2, q % 4) * dp[q]) % 10;
        } else {
            // i보다 작은 가장 큰 5의 배수를 구함
            int before = (i / 5) * 5;
            int total = 1;
            for(int j = i; j > before; j--) {
                total *= (j % 10);
            }

            total *= dp[before];
            dp[i] = total % 10;
        }
    }

    cout << dp[N] << '\n';
}