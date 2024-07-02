#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q, inp;
    cin >> N;

    vector<int> intervals(N, 0);

    for(int i=0; i < N; i++) {
        cin >> intervals[i];
    }

    for(int i=0; i < N; i++) {
        cin >> inp;
        intervals[i] -= inp;
    }

    cin >> Q;
    vector<int> sizes(Q, 0);
    map<int, int> maximum_scores;
    int prev_min = intervals[0];

    for(int i=1; i < N; i++) {
        if(prev_min > intervals[i]) {
            maximum_scores[prev_min] =  i;
            prev_min = intervals[i];
        }
    }
    maximum_scores[prev_min] = N;
    
    for(int i=0; i < Q; i++) {
        cin >> inp;
        auto it = maximum_scores.lower_bound(inp);
        if(it == maximum_scores.end()) {
            cout << 0 << '\n';
        } else {
            cout << it->second << '\n';
        }
    }
}