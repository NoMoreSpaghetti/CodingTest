#include <iostream>
using namespace std;

int T;

int gcd(int a, int b) {
    int c;

    while(b != 0) {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    int A, B;

    while(T--) {
        cin >> A >> B;
        cout << lcm(A, B) << '\n';
    }
}