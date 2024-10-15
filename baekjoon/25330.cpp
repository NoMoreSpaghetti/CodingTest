#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<pair<int, int>> vills;

int recursive(int i, int k, int sum) {
    if(i > N) {
        return 0;
    }

    int return_val = 0;
    int next_k = k - (sum + vills[i].first);
    if(next_k >= 0) {
        return_val = recursive(i + 1, next_k, sum + vills[i].first) + vills[i].second;
    }
    return max(return_val, recursive(i + 1, k, sum));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    vills = vector<pair<int, int>>(N + 1, {0, 0});

    for(int i=1; i <= N; i++) {
        cin >> vills[i].first;
    }

    for(int i=1; i <= N; i++) {
        cin >> vills[i].second;
    }

    sort(vills.begin(), vills.end());

    cout << recursive(1, K, 0) << '\n';
}