#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

string S, T;

int bfs() {
    queue<pair<string, bool>> q;
    q.push({T, 0});
    int target_len = S.length();

    while(!q.empty()) {
        string s = q.front().first;
        bool reversed = q.front().second;
        q.pop();

        if(s.length() == target_len) {
            if(reversed) {
                reverse(s.begin(), s.end());
            }
            if(s.compare(S) == 0) {
                return 1;
            }
            continue;
        }
        if(reversed) {
            if(s[0] == 'A') {
                q.push({s.substr(1), reversed});
            }
            if(s[s.length() - 1] == 'B') {
                q.push({s.substr(0, s.length() - 1), !reversed});
            }
        } else {
            if(s[s.length() - 1] == 'A') {
                q.push({s.substr(0, s.length() - 1), reversed});
            }
            if(s[0] == 'B') {
                q.push({s.substr(1), !reversed});
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S >> T;

    cout << bfs() << '\n';
}