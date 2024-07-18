#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, A, B, C;
    cin >> T;

    while(T--) {
        cin >> N;
        int ans = 0;
        for(int i=0; i < N; i++) {
            cin >> A >> B >> C;
            int max_val = max(A, max(B, C));
            if(max_val > 0) {
                ans += max_val;
            }
        }
        cout << ans << '\n';
    }
}