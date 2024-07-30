#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int cur_h, next_h;
    int ans = 0;
    cin >> cur_h;

    for(int i=1; i < N; i++) {
        cin >> next_h;
        ans += pow(cur_h - next_h, 2) + pow(cur_h + next_h, 2);
        cur_h = next_h;
    }

    cout << ans << '\n';
}