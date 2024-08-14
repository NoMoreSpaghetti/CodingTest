#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, R, C;
    cin >> N >> R >> C;

    int start = 0;
    if(abs(R - C) % 2 == 1) {
        start = 1;
    }

    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            if((i + j) % 2 == start) {
                cout << 'v';
            } else {
                cout << '.';
            }
        }
        cout << '\n';
    }
}