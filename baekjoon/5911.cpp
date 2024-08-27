#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, B;
    cin >> N >> B;
    vector<vector<long long>> P(N, vector<long long>(3, 0));

    for(int i=0; i < N; i++) {
        cin >> P[i][2] >> P[i][1];
        P[i][0] = P[i][1] + P[i][2];
    }

    sort(P.begin(), P.end());

    int ans = 0;
    long long prev_max_P = 0;
    for(int i=0; i < N; i++) {
        if(B >= P[i][0]) {
            B -= P[i][0];
            prev_max_P = max(prev_max_P, P[i][2]);
            ans++;
        } else {
            prev_max_P = max(prev_max_P, P[i][2]);
            if(B + prev_max_P / 2 >= P[i][0]) {
                ans++;
            } 
            break;
        }
    }
    cout << ans << '\n';
}