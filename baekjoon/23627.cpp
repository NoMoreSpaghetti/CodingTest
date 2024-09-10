#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    if(s.length() >= 5 && s.substr(s.length() - 5, 5) == "driip") {
        cout << "cute" << '\n';
    } else {
        cout << "not cute" << '\n';
    }
}