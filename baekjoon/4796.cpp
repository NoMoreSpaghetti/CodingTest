#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int L, P, V;
    int t = 1;
    cin >> L >> P >> V;
    while(L != 0 && P != 0 && V != 0) {
        int answer = (V / P) * L;
        answer += min(V % P, L);

        cout << "Case " << t++ << ": " << answer << '\n';
        cin >> L >> P >> V;
    }
}