#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string inp;
    cin >> inp;

    int h, m, s;

    h = stoi(inp.substr(0, inp.find(':')));
    m = stoi(inp.substr(inp.find(':') + 1));

    s = 0;
    s -= m;
    if(s < 0) {
        s += 60;
        m -= 1;
    }

    m -= h;
    if(m < 0) {
        m += 60;
        h -= 1;
    }

    vector<string> strs = {to_string(h), to_string(m), to_string(s)};

    for(string& s : strs) {
        if(s.length() < 2) {
            s.insert(s.begin(), '0');
        }
    }

    cout << strs[0] << ':' << strs[1] << ':' << strs[2] << '\n';
}