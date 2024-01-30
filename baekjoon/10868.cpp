#include <iostream>
#include <vector>
using namespace std;

int N, M;


class SegTree {
public:
    SegTree(const vector<int>& arr, int arr_size)
    : range_min(arr_size * 4, 0), arr_size(arr_size)
    {
        Init(arr, 1, 0, arr_size - 1);
    }

    int Init(const vector<int>& arr, int cur_idx, int left_idx, int right_idx) {
        if(left_idx == right_idx) {
            return range_min[cur_idx] = arr[left_idx];
        }
        int mid = (left_idx + right_idx) / 2;
        int left_val = Init(arr, cur_idx * 2, left_idx, mid);
        int right_val = Init(arr, cur_idx * 2 + 1, mid + 1, right_idx);
        return range_min[cur_idx] = min(left_val, right_val);
    }

    int FindMin(int left, int right) {
        return FindMin(left, right, 1, 0, arr_size - 1);
    }

    int FindMin(int left, int right, int cur_idx, int left_idx, int right_idx) {
        if(left <= left_idx && right >= right_idx) {
            return range_min[cur_idx];
        }
        if(left > right_idx || right < left_idx) {
            return INT32_MAX;
        }
        int mid = (left_idx + right_idx) / 2;
        int left_min = FindMin(left, right, cur_idx * 2, left_idx, mid);
        int right_min = FindMin(left, right, cur_idx * 2 + 1, mid + 1, right_idx);
        return min(left_min, right_min);
    }

private:
    int arr_size;
    vector<int> range_min;
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    int a, b;
    vector<int> nums(N, 0);

    for(int i=0; i < N; i++) {
        cin >> nums[i];
    }

    SegTree tree(nums, N);

    for(int i=0; i < M; i++) {
        cin >> a >> b;
        cout << tree.FindMin(a - 1, b -1) << '\n';
    }
}