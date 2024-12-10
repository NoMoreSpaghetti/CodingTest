#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, p, q;
    char a, b;
    string inp;

    cin >> n;

    for(int t=1; t <= n; t++) {
        cout << "Test case #" << t << ": " << '\n';
        map<char, char> m;

        cin >> p;

        for(int i=0; i < p; i++) {
            cin >> a >> b;
            m.insert({a, b});
            m.insert({b, a});
        }

        cin >> q;
        for(int i=0; i < q; i++) {
            bool is_palindrome = true;
            cin >> inp;
            for(int j=0; j < inp.size() / 2; j++) {
                if(inp[j] == inp[inp.size() - 1 - j]) continue;
                if(inp[j] == m[inp[inp.size() - 1 - j]]) continue;

                is_palindrome = false;
                break;
            }
            cout << inp << ' ';
            if(is_palindrome) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
        cout << '\n';
    }
}