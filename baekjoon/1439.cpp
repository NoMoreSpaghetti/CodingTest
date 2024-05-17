#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    int shorten_len = 1;
    for(int i=1; i < s.size(); i++) {
        while(i < s.size() && s[i] == s[i - 1]) {
            i++;
        }
        if(i != s.size()) {
            shorten_len++;
        } else {
            break;
        }
    }

    cout << shorten_len / 2 << '\n';
}