#include <iostream>
using namespace std;

// 반대 부호의 값에 갔다가 0으로 되돌아온 다음
// 0에서부터 목표 지점까지의 값을 더하기

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    long long x;

    while(T--) {
        cin >> x;

        if(x == 0) {
            cout << 0 << '\n';
        } else if(x == 1) {
            cout << 1 << '\n';
        } else if(x == -1) {
            cout << 3 << '\n';
        } else {
            long long x_copy = abs(x);
            long long lower_pow_2 = 1;
            while(x_copy > (lower_pow_2 << 1)) {
                lower_pow_2 <<= 1;
            }

            long long ans = (lower_pow_2 * 2 - 1) * 4;
            if(x > 0) {
                ans += x;
            } else {
                lower_pow_2 <<= 1;
                ans += lower_pow_2 * 2 + x_copy;
            }

            cout << ans << '\n';
        }
    }
}
