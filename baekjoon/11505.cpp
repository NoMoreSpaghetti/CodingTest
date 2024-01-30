#include <iostream>
#include <vector>
#define DIV_NUM (1000000007)
using namespace std;

int N, M, K;

class Tree {
public:
    Tree(vector<int>& arr, int size) 
    : range_mul(size * 4, 0), arr_size(size)
    {
        Init(arr, 1, 0, arr.size() - 1);
    }

    long long Init(vector<int>& arr, int cur_node, int left_idx, int right_idx) {
        if(left_idx == right_idx) {
            return range_mul[cur_node] = arr[left_idx];
        }
        int mid = (left_idx + right_idx) / 2;
        long long left_val = Init(arr, cur_node * 2, left_idx, mid);
        long long right_val = Init(arr, cur_node * 2 + 1, mid + 1, right_idx);
        return range_mul[cur_node] = (left_val * right_val) % DIV_NUM;
    }

    long long GetMul(int left, int right) {
        return GetMul(left, right, 1, 0, arr_size - 1);
    }

    long long GetMul(int left, int right, int cur_node, int left_idx, int right_idx) {
        if(right < left_idx || left > right_idx) {
            return 1;
        }
        if(left <= left_idx && right_idx <= right) {
            return range_mul[cur_node];
        }
        int mid = (left_idx + right_idx) / 2;
        long long left_val = GetMul(left, right, cur_node * 2, left_idx, mid);
        long long right_val = GetMul(left, right, cur_node * 2 + 1, mid + 1, right_idx);
        return (left_val * right_val) % DIV_NUM;
    }

    void Update(int idx, int n) {
        Update(idx, n, 1, 0, arr_size - 1);
    }

    long long Update(int idx, long long n, int cur_node, int left_idx, int right_idx) {
        if(idx < left_idx || idx > right_idx) {
            return range_mul[cur_node];
        }
        if(left_idx == right_idx) {
            range_mul[cur_node] = n;
            return n;
        } else {
            int mid = (left_idx + right_idx) / 2;
            long long left_val = Update(idx, n, cur_node * 2, left_idx, mid);
            long long right_val = Update(idx, n, cur_node * 2 + 1, mid + 1, right_idx);

            return range_mul[cur_node] = (left_val * right_val) % DIV_NUM;
        }
    }

private:
    int n;
    int arr_size;
    vector<long long> range_mul;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    int a, b, c;
    vector<int> nums(N, 0);

    for(int i=0; i < N; i++) {
        cin >> nums[i];
    }

    Tree tree(nums, N);

    for(int i=0; i < M + K; i++) {
        cin >> a >> b >> c;
        if(a == 1) {
            tree.Update(b - 1, c);
        } else {
            cout << tree.GetMul(b - 1, c - 1) << '\n';
        }
    }
}