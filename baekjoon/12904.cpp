#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S, T;
    queue<string> q;
    cin >> S >> T;

    int S_len = S.length();
    int answer = 0;

    for(int i=T.length() - 1; i >= 0; i--) {
        if(T[i] == 'A') {
            T = T.substr(0, i);
        } else if(T[i] == 'B') {
            T = T.substr(0, i);
            reverse(T.begin(), T.end());
        }
        if(T.length() == S_len) {
            if(S.compare(T) == 0) {
                answer = 1;
            }
        }
    }

    cout << answer << '\n';
}