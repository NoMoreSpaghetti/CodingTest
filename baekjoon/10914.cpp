#include <iostream>
#include <sstream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    string s;
    while(cin >> s) {
        for(int i=1; i < s.length(); i+= 2) {
            cout << static_cast<char>((s[i - 1] - 'a' + s[i] - 'a' - n + 26) % 26 + 'a');
        }
        cout << ' ';
    }
}