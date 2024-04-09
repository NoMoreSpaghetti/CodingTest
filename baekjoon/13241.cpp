#include <iostream>
#include <vector>
using namespace std;

long long int get_gcd(long long int a, long long int b) {
    long long int c;

    while(b != 0) {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

long long int get_lcm(long long int a, long long int b) {
    return a * (b / get_gcd(a, b));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int A, B;
    cin >> A >> B;

    cout << get_lcm(A, B) << '\n';
}