#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> vec(N, 0);
    vector<int> num_leafs(N + 1, 0);
    priority_queue<int, vector<int>, greater<int>> leaf_pq;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;

    for(int i=0; i < N - 2; i++) {
        cin >> vec[i];
        num_leafs[vec[i]]++;
    }

    for(int i=1; i <= N; i++) {
        if(num_leafs[i] == 0){
            leaf_pq.push(i);
        }
    }

    int vec_idx = 0;
    for(int i=0; i < N - 2; i++) {
        int leaf = leaf_pq.top();
        leaf_pq.pop();

        pq2.push({min(leaf, vec[vec_idx]), max(leaf, vec[vec_idx])});

        if(num_leafs[vec[vec_idx]] == 1) {
            leaf_pq.push(vec[vec_idx]);
        }

        num_leafs[vec[vec_idx]]--;

        vec_idx++;
    }

    pair<int, int> last_edge;
    last_edge.first = leaf_pq.top();
    leaf_pq.pop();
    last_edge.second = leaf_pq.top();
    leaf_pq.pop();
    if(last_edge.first > last_edge.second) {
        swap(last_edge.first, last_edge.second);
    }
    pq2.push({last_edge});

    while(!pq2.empty()) {
        cout << pq2.top().first << ' ' << pq2.top().second << '\n';
        pq2.pop();
    }
}