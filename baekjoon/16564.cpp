#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<int> levels(N, 0);

    for(int i=0; i < N; i++) {
        cin >> levels[i];
    }

    sort(levels.begin(), levels.end());

    long long min_lev = levels[0], max_lev = 2000000000;
    long long mid_lev, remain_k;

    while(min_lev <= max_lev) {
        remain_k = K;
        mid_lev = (min_lev + max_lev) / 2;
        
        int i=0;
        for(; i < N; i++) {
            remain_k -= mid_lev - levels[i];
            if(remain_k < 0) {
                break;
            }
        }

        if(remain_k < 0) {
            max_lev = mid_lev - 1;
        } else {
            min_lev = mid_lev + 1;
        }
    }
    cout << max_lev << '\n';
}