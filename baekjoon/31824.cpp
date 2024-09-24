#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    string Q, A, S;
    cin >> N >> M;

    unordered_map<string, string> m;

    for(int i=0; i < N; i++) {
        cin >> Q >> A;
        m[Q] = A;
    }

    for(int i=0; i < M; i++) {
        bool valid = false;
        cin >> S;
        int s_len = S.length();
        for(int j=0; j < s_len; j++) {
            for(int k=1; k + j <= s_len; k++) {
                string sub_s = S.substr(j, k);
                if(m.find(sub_s) != m.end()) {
                    cout << m[sub_s];
                    valid = true;
                }
            }
        }
        if(!valid) {
            cout << -1;
        }
        cout << '\n';
    }
}