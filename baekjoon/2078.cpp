#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, L = 0, R = 0;
    cin >> A >> B;

    while(!(A == 1 && B == 1)) {
        if(A > B) {
            int num = (A - 1) / B;
            L += num;
            A -= num * B;
        } else {
            int num = (B - 1) / A;
            R += num;
            B -= num * A;
        }
    }

    cout << L << ' ' << R << '\n';
}