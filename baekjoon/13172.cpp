#include <iostream>
using namespace std;

int X = 1000000007;

long long fast_pow(long long n, long long num) {
    long long return_val = 1;
    while(num) {
        if(num % 2) {
            return_val *= n;
            return_val %= X;
        }
        n *= n;
        n %= X;
        num >>= 1;
    }
    return return_val;
}

long long get_inverse(long long n) {
    int num_pow = X - 2;
    return fast_pow(n, num_pow);
}

int get_mod_of_fraction(long long n, long long s) {
    long long inverse = get_inverse(n);
    return (s * inverse) % X;
}

int main() {
    int M;
    int ans = 0;
    long long n, s;
    cin >> M;

    for(int m=0; m < M; m++) {
        cin >> n >> s;
        ans += get_mod_of_fraction(n, s);
        ans %= X;
    }

    cout << ans << '\n';
}