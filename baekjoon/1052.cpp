#include <iostream>
using namespace std;

int N, K;
int bits = 1;

int bitCount(int bit) {
    if(bit == 0) return 0;
    return bit % 2 + bitCount(bit / 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    int bit = 0;

    int i = 0;
    while(N > 0) {
        if(N % 2 == 1) {
            bit |= (1 << i);
        }
        N /= 2;
        i++;
    }

    int sum = bitCount(bit);
    int j = 0;
    int cnt = 0;
    int ans = 0;
    while(sum > K) {
        while(bit & (1 << j)) {
            cnt++;
            j++;
        }
        sum -= cnt - 1;
        bit += (1 << (j - cnt));
        ans += (1 << (j - cnt));
        cnt = 0;
    }
    cout << ans << '\n';
}