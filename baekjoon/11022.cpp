#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, A, B;
    cin >> T;

    for(int t=1; t <= T; t++) {
        cin >> A >> B;
        cout << "Case #" << t << ": " << A << " + " << B << " = " << A + B << '\n';
    }
}