#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, A, B;
    cin >> T;

    while(T--) {
        cin >> A >> B;
        cout << (A + B) << '\n';
    }
}