#include <iostream>
using namespace std;

int EEA(int a, int b) {
    // 확장 유클리드 알고리즘
    int r1 = a, r2 = b;
    int s1 = 1, s2 = 0;
    int t1 = 0, t2 = 1;
    int temp, q;

    while(r2) {
        q = r1 / r2;
        temp = r1 - q * r2;
        r1 = r2;
        r2 = temp;
        temp = t1 - q * t2;
        t1 = t2;
        t2 = temp;
        temp = s1 - q * s2;
        s1 = s2;
        s2 = temp;
    }

    if(r1 != 1) {
        return 0;
    }
    if(t1 < 0) {
        t1 += a;
    }
    return t1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int E, S, M;
    cin >> E >> S >> M;

    int rev_a = EEA(15, 28 * 19);
    int rev_b = EEA(28, 19 * 15);
    int rev_c = EEA(19, 15 * 28);

    // 중국인의 나머지 정리
    // x = E (mod 15)
    // x = S (mod 28)
    // x = M (mod 19)

    // x = E(mod 28 * 19)
    // x = S(mod 15 * 19)
    // x = M(mod 15 * 28)

    int ans = ((rev_a * 28 * 19 * E) + (rev_b * 15 * 19 * S) + (rev_c * 15 * 28 * M)) % (15 * 28 * 19);
    if(ans == 0) {
        ans = 15 * 28 * 19;
    }

    cout << ans << '\n';
}