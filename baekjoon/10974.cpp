#include <iostream>
#include <vector>
using namespace std;

int N;

void recursive_print(int n, int bit, string s) {
    if(n == 0) {
        cout << s << '\n';
    } else {
        for(int i=1; i <= N; i++) {
            if(!(bit & (1 << i))) {
                if(n == 1) {
                    recursive_print(n - 1, bit | (1 << i), s + (char)(i + '0'));
                } else {
                    recursive_print(n - 1, bit | (1 << i), s + (char)(i + '0') + " ");
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    recursive_print(N, 0, "");
}