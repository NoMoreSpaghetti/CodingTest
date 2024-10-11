#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;

int calc_dist(pair<int, int>& a, pair<int, int>& b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<pair<int, int>> checkpoints(N, {0, 0});

    vector<int> dists(N, 0);

    for(int i=0; i < N; i++) {
        cin >> checkpoints[i].first >> checkpoints[i].second;
    }

    int idx = 0;
    int max_val = 0;
    int ans = 0;

    dists[1] = calc_dist(checkpoints[0], checkpoints[1]);
    ans += dists[1];

    for(int i=2; i < N - 1; i++) {
        dists[i] = calc_dist(checkpoints[i - 1], checkpoints[i]);

        ans += dists[i];

        int sub_dist = dists[i - 1] + dists[i] - calc_dist(checkpoints[i - 2], checkpoints[i]);
        if(max_val < sub_dist) {
            max_val = sub_dist;
            idx = i;
        }
    }

    dists[N - 1] = calc_dist(checkpoints[N - 2], checkpoints[N - 1]);
    ans += dists[N - 1];

    ans -= max_val;

    cout << ans << '\n';
}