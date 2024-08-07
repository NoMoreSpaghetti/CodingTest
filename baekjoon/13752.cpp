#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, inp;
    cin >> n;

    for(int i=0; i < n; i++) {
        cin >> inp;
        for(int j=0; j < inp; j++) {
            cout << '=';
        }
        cout << '\n';
    }
}