#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    int left = 0, right = 0;
    int i=0;

    for(; i < s.length(); i++) {
        if(s[i] == '@') {
            left++;
        } else if(s[i] == '(') {
            i += 4;
            break;
        }
    }

    for(; i < s.length(); i++) {
        if(s[i] == '@') {
            right++;
        }
    }

    cout << left << ' ' << right << '\n';
}