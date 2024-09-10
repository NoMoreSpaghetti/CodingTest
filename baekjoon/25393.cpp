#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q, l, r;
    cin >> N;

    unordered_map<int, vector<int>> intervals;
    unordered_map<int, vector<int>> intervals_reverse;

    for(int i=0; i < N; i++) {
        cin >> l >> r;

        intervals[l].push_back(r);
        intervals_reverse[r].push_back(l);
    }   

    for(auto iter=intervals.begin(); iter != intervals.end(); iter++) {
        sort(iter->second.begin(), iter->second.end());
    }

    for(auto iter=intervals_reverse.begin(); iter != intervals_reverse.end(); iter++) {
        sort(iter->second.begin(), iter->second.end(), greater<int>());
    }

    cin >> Q;
    while(Q--) {
        cin >> l >> r;

        if(intervals.count(l) && intervals_reverse.count(r)) {
            vector<int>& left_vec = intervals[l];
            vector<int>& right_vec = intervals_reverse[r];

            vector<int>::iterator left_it = lower_bound(left_vec.begin(), left_vec.end(), r);
            vector<int>::iterator right_it = lower_bound(right_vec.begin(), right_vec.end(), l, greater<int>());

            if(left_it != left_vec.end() && right_it != right_vec.end()) {
                if(*left_it == r) {
                    cout << 1 << '\n';
                } else {
                    cout << 2 << '\n';
                }
                continue;
            }
        }
        cout << -1 << '\n';
    }
}