#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int c, d, n;
    cin >> c;

    while(c--) {
        cin >> d >> n;
        vector<long long> cumulative_sum(n + 1, 0);
        vector<long long> mod_cnts(d, 0);

        for(int i=1; i <= n; i++) {
            cin >> cumulative_sum[i];
            cumulative_sum[i] += cumulative_sum[i - 1];
            mod_cnts[cumulative_sum[i] % d]++;
        }

        int answer = mod_cnts[0];

        for(int i=0; i < d; i++) {
            if(mod_cnts[i] >= 2) {
                answer += mod_cnts[i] * (mod_cnts[i] - 1) / 2;
            }
        }

        cout << answer << '\n';
    }
}