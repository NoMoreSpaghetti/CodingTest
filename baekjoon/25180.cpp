#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int ans = 1;

    if(N > 9) {
        ans += 1;
        N -= min(18, (N >> 1) * 2);
        
        while(N > 9) {
            ans += 2;
            N -= min(18, (N >> 1) * 2);
        }

        if(N > 0) {
            ans += 1;
        }
    }
    cout << ans << '\n';
}