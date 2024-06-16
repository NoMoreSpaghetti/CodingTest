#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    string num_str;
    cin >> s;
    while(s != "#") {
        int bit = 0;
        int idx = 0;
        while(idx < s.size() - 1) {
            bit ^= s[idx] - '0';
            idx++;
        }

        if(s.back() == 'e') {
            s.back() = '0' + bit;
        } else {
            s.back() = (bit) ? '0' : '1';
        }

        cout << s << '\n';

        cin >> s;
    }
}