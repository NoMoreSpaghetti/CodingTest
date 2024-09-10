#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    long long N;
    cin >> T;

    while(T--) {
        cin >> N;
        if(N % 10 == 0) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}
