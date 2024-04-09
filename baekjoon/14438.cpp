#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M;

vector<int> segtree;

int Init(const vector<int>& nums, int node, int node_left, int node_right) {
    if(node_left == node_right) {
        return segtree[node] = nums[node_left];
    }
    
    int mid_idx = (node_left + node_right) >> 1;
    return segtree[node] = min(Init(nums, node * 2, node_left, mid_idx), Init(nums, node * 2 + 1, mid_idx + 1, node_right));
}

int Update(int target_idx, int val, int node, int node_left, int node_right) {
    if(target_idx < node_left || target_idx > node_right) {
        return segtree[node];
    }

    if(node_left == node_right) {
        return segtree[node] = val;
    }

    int mid_idx = (node_left + node_right) >> 1;
    return segtree[node] = min(Update(target_idx, val, node * 2, node_left, mid_idx), Update(target_idx, val, node * 2 + 1, mid_idx + 1, node_right));
}

int Query(int left, int right, int node, int node_left, int node_right) {
    if(left > node_right || right < node_left) {
        return INT32_MAX;
    }
    if(left <= node_left && right >= node_right) {
        return segtree[node];
    }

    int mid_idx = (node_left + node_right) >> 1;
    return min(Query(left, right, node * 2, node_left, mid_idx), Query(left, right, node * 2 + 1, mid_idx + 1, node_right));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int op, a, b;
    cin >> N;
    vector<int> vec(N, 0);

    for(int i=0; i < N; i++) {
        cin >> vec[i];
    }
    segtree = vector<int>(1 << ((int)ceil(log2(N)) + 1), 0);
    Init(vec, 1, 0, N - 1);

    cin >> M;

    while(M--) {
        cin >> op >> a >> b;
        if(op == 1) {
            Update(a - 1, b, 1, 0, N - 1);
        } else {
            cout << Query(a - 1, b - 1, 1, 0, N - 1) << '\n';
        }
    }

    return 0;
}