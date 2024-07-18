#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int P, N;
    cin >> P >> N;
    vector<int> accessories(N, 0);

    for(int i=0; i < N; i++) {
        cin >> accessories[i];
    }

    sort(accessories.begin(), accessories.end());
    int ans = 0;
    for(int i=0; i < N; i++) {
        if(P >= 200) {
            break;
        }
        P += accessories[i];
        ans++;
    }
    cout << ans << '\n';
}