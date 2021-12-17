#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sH, sM, eH, eM, N;
    bool include_N[60] = {0};
    cin >> sH >> sM >> eH >> eM >> N;

    int n_in_60M = 0;
    for(int i=0; i <= 59; i++) {
        if(i % 10 == N || i / 10 == N) {
            include_N[i] = true;
            n_in_60M++;
        }
    }

    int ans = 0;

    for(int i=sH; i <= eH; i++) {
        int cur_sM = 0, cur_eM = 59;
        if(i == sH) {
            cur_sM = sM;
        }
        if(i == eH) {
            cur_eM = eM;
        }
        if(include_N[i]) {
            ans += cur_eM - cur_sM + 1;
        } else if(i != sH && i != eH) {
            ans += n_in_60M;
        } else {
            for(int j=cur_sM; j <= cur_eM; j++) {
                ans += include_N[j] ? 1 : 0;
            }
        }
    }

    cout << ans << '\n';
}