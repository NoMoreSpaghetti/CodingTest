#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c, d, N, u, v;
    cin >> a >> b >> c >> d >> N;

    int ans = 0;
    for(int i=0; i < N; i++) {
        cin >> u >> v;
        if(max(a * (v - b) * (v - b) + c, d) == u) {
            ans++;
        }
    }

    cout << ans << '\n';
}