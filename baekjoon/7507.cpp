#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, d, s, e;

    cin >> n;

    for(int i=0; i < n; i++) {
        cin >> m;
        
        // {end time, start time} 저장
        vector<pair<int, int>> games(m, {0, 0});

        for(int j=0; j < m; j++) {
            cin >> d >> s >> e;
            int start_time = 1440 * d + s / 100 * 60 + s % 100;
            int end_time = 1440 * d + e / 100 * 60 + e % 100;
            games[j] = {end_time, start_time};
        }

        sort(games.begin(), games.end());

        int ans = 1;
        int prev_end_time = games[0].first;
        for(int j=1; j < m; j++) {
            if(games[j].second >= prev_end_time) {
                prev_end_time = games[j].first;
                ans++;
            }
        }

        cout << "Scenario #" << i + 1 << ":\n" << ans << "\n\n";
    }
}