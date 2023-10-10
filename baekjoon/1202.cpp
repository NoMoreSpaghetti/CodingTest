#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, m, v, c;
    cin >> N >> K;

    vector<int> backpacks(K, 0);
    vector<pair<int, int>> jewels(N, {0, 0});

    for(int n=0; n < N; n++) {
        cin >> m >> v;
        jewels[n] = {m, v};
    }

    for(int k=0; k < K; k++) {
        cin >> c;
        backpacks[k] = c;
    }

    sort(jewels.begin(), jewels.end(), cmp);
    sort(backpacks.begin(), backpacks.end());

    long long sum = 0;
    int jewel_idx = 0;
    priority_queue<int> pq;
    for(auto& c: backpacks) {
        for(; jewel_idx < N && jewels[jewel_idx].first <= c; jewel_idx++) {
            pq.push(jewels[jewel_idx].second);
        }

        if(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }

    cout << sum << '\n';
}