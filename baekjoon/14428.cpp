#include <iostream>
#include <vector>
using namespace std;

int N, M;

class SegTree{
public:
    SegTree(const vector<int>& arr, int arr_size)
    : range_min(arr_size * 4, {0, 0}), arr_size(arr_size)
    {
        Init(arr, 1, 0, arr_size - 1);
    }

    pair<int, int> Init(const vector<int>& arr, int cur_idx, int left_idx, int right_idx) {
        if(left_idx == right_idx) {
            return range_min[cur_idx] = {left_idx, arr[left_idx]};
        }
        int mid_idx = (left_idx + right_idx) / 2;
        pair<int, int> left_val = Init(arr, cur_idx * 2, left_idx, mid_idx);
        pair<int, int> right_val = Init(arr, cur_idx * 2 + 1, mid_idx + 1, right_idx);

        if(left_val.second > right_val.second) {
            return range_min[cur_idx] = right_val;
        } else {
            return range_min[cur_idx] = left_val;
        }
    }

    void Update(int target_idx, int val) {
        Update(target_idx, val, 1, 0, arr_size - 1);
    }

    pair<int, int> Update(int target_idx, int val, int cur_idx, int left_idx, int right_idx) {
        if(target_idx > right_idx || target_idx < left_idx) {
            return range_min[cur_idx];
        }

        if(left_idx == right_idx) {
            return range_min[cur_idx] = {target_idx, val};
        }

        int mid_idx = (left_idx + right_idx) / 2;
        pair<int, int> left_val = Update(target_idx, val, cur_idx * 2, left_idx, mid_idx);
        pair<int, int> right_val = Update(target_idx, val, cur_idx * 2 + 1, mid_idx + 1, right_idx);

        if(left_val.second > right_val.second) {
            return range_min[cur_idx] = right_val;
        } else {
            return range_min[cur_idx] = left_val;
        }
    }

    int FindMin(int left, int right) {
        return FindMin(left, right, 1, 0, arr_size - 1).first + 1;
    }

    pair<int, int> FindMin(int left, int right, int cur_idx, int left_idx, int right_idx) {
        if(left <= left_idx && right >= right_idx) {
            return range_min[cur_idx];
        }
        if(left > right_idx || right < left_idx) {
            return {-1, INT32_MAX};
        }
        int mid_idx = (left_idx + right_idx) / 2;
        pair<int, int> left_val = FindMin(left, right, cur_idx * 2, left_idx, mid_idx);
        pair<int, int> right_val = FindMin(left, right, cur_idx * 2 + 1, mid_idx + 1, right_idx);

        if(left_val.second > right_val.second) {
            return right_val;
        } else {
            return left_val;
        }
    }

private:
    vector<pair<int, int>> range_min;
    int arr_size;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<int> vec(N, 0);

    for(int i=0; i < N; i++) {
        cin >> vec[i];
    }

    SegTree tree(vec, N);
    int op, a, b;
    cin >> M;
    for(int i=0; i < M; i++) {
        cin >> op >> a >> b;
        if(op == 1) {
            tree.Update(a - 1, b);
        } else {
            cout << tree.FindMin(a - 1, b - 1) << '\n';
        }
    }
}