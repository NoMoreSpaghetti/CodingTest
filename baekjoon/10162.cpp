#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    int buttons[3] = {300, 60, 10};

    if(T % 10 != 0) {
        cout << -1 << '\n';
    } else {
        for(int i=0; i < 3; i++) {
            cout << T / buttons[i] << ' ';
            T %= buttons[i];
        }
    }
}