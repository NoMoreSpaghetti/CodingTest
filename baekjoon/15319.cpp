#include <iostream>
#include <vector>
using namespace std;

const long long DIV_NUM = 1000000007;

long long GetPow(long long x, long long pow_num) {
    if(pow_num == 0) return 1;
    if(pow_num == 1) return x;
    
    if(pow_num % 2 == 1) return (GetPow(x, pow_num - 1) * x) % DIV_NUM;
    long long sqrt_num = GetPow(x, pow_num / 2) % DIV_NUM;
    return (sqrt_num * sqrt_num) % DIV_NUM;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, x, K;

    cin >> N;

    long long ans = 0;

    for(int i=0; i < N; i++) {
        cin >> x >> K;

        long long M = 0;
        int bit_idx = 0;
        while(K) {
            if(K & 1) {
                M += GetPow(x, bit_idx);
            }
            bit_idx++;
            K >>= 1;
        }
        ans += M;
        ans %= DIV_NUM;
    }

    cout << ans << '\n';
}