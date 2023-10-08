#include <iostream>
#include <limits.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned long long X, K, ans = 0;
    cin >> X >> K;

    unsigned long long i = 0;
    while(K) {
        if((X & 1) == 0) {
            ans += (K & 1) << i;
            K >>= 1;
        }
        i++;
        X >>= 1;
    }

    cout << ans << '\n';
}
