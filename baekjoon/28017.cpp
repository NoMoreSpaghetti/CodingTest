#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, t;
    cin >> N >> M;

    vector<vector<int>> times(N, vector<int>(M, INT32_MAX));

    for(int j=0; j < M; j++) {
        cin >> times[0][j];
    }

    for(int i=1; i < N; i++) {
        for(int j=0; j < M; j++) {
            cin >> t;
            for(int k=0; k < M; k++) {
                if(j == k) {
                    continue;
                }
                times[i][j] = min(times[i][j], times[i - 1][k]);
            }
            times[i][j] += t;
        }
    }

    int ans = INT32_MAX;
    for(int i=0; i < M; i++) {
        ans = min(ans, times[N - 1][i]);
    }

    cout << ans << '\n';

}