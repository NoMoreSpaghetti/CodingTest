#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    int N = s.length();
    bool is_simple = true;

    for(int i=1; i < N; i++) {
        if(s[i - 1] != s[i]) {
            is_simple = false;
            break;
        }
    }

    if(is_simple) {
        cout << -1 << '\n';
    } else {
        int i = 0;
        for(; i < N / 2; i++) {
            if(s[i] != s[N - 1 - i]) {
                break;
            }
        }
        if(i == N / 2) {
            cout << N - 1 << '\n';
        } else {
            cout << N << '\n';
        }
    }
}