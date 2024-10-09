#include <iostream>
#include <vector>
#define MAX_VAL (100000000)
using namespace std;

struct Node {
    int sum;
    int l_sum;
    int r_sum;
    int max_partial_sum;
};

class SegTree {
public:
    SegTree(const vector<int>& arr, int arr_size, int U, int V)
    : range_sum(arr_size * 4, Node()), arr_size(arr_size), U(U), V(V)
    {
        Init(arr, 1, 0, arr_size - 1);
    }
    
    Node Init(const vector<int>& arr, int cur_idx, int left_idx, int right_idx) {
        if(left_idx == right_idx) {
            range_sum[cur_idx].sum = arr[left_idx] * U + V;
            range_sum[cur_idx].l_sum = range_sum[cur_idx].sum;
            range_sum[cur_idx].r_sum = range_sum[cur_idx].sum;
            range_sum[cur_idx].max_partial_sum = range_sum[cur_idx].sum;
            return range_sum[cur_idx];
        }

        int mid = (left_idx + right_idx) / 2;
        Node left_val = Init(arr, cur_idx * 2, left_idx, mid);
        Node right_val = Init(arr, cur_idx * 2 + 1, mid + 1, right_idx);
        range_sum[cur_idx].sum = left_val.sum + right_val.sum;
        range_sum[cur_idx].l_sum = max(left_val.l_sum, left_val.sum + right_val.l_sum);
        range_sum[cur_idx].r_sum = max(right_val.r_sum, left_val.r_sum + right_val.sum);
        range_sum[cur_idx].max_partial_sum = max(max(left_val.max_partial_sum, right_val.max_partial_sum), left_val.r_sum + right_val.l_sum);
        return range_sum[cur_idx];
    }

    Node Sum(int left, int right) {
        return Sum(left, right, 1, 0, arr_size - 1);
    }

    Node Sum(int left, int right, int cur_idx, int left_idx, int right_idx) {
        if(left <= left_idx && right >= right_idx) {
            return range_sum[cur_idx];
        }

        if(left > right_idx || right < left_idx) {
            Node a = {0, -MAX_VAL, -MAX_VAL, -MAX_VAL};
            return a;
        }

        int mid_idx = (left_idx + right_idx) / 2;
        Node left_val = Sum(left, right, cur_idx * 2, left_idx, mid_idx);
        Node right_val = Sum(left, right, cur_idx * 2 + 1, mid_idx + 1, right_idx);

        Node return_node;

        return_node.sum = left_val.sum + right_val.sum;
        return_node.l_sum = max(left_val.l_sum, left_val.sum + right_val.l_sum);
        return_node.r_sum = max(right_val.r_sum, left_val.r_sum + right_val.sum);
        return_node.max_partial_sum = max(max(left_val.max_partial_sum, right_val.max_partial_sum), left_val.r_sum + right_val.l_sum);

        return return_node;
    }

    void Update(int target_idx, int val) {
        Update(target_idx, val, 1, 0, arr_size - 1);
    }

    Node Update(int target_idx, int val, int cur_idx, int left_idx, int right_idx) {
        if(target_idx < left_idx || target_idx > right_idx) {
            return range_sum[cur_idx];
        }
        
        if(left_idx == right_idx) {
            range_sum[cur_idx].sum = val * U + V;
            range_sum[cur_idx].l_sum = val * U + V;
            range_sum[cur_idx].r_sum = val * U + V;
            range_sum[cur_idx].max_partial_sum = val * U + V;

            return range_sum[cur_idx];
        }

        int mid_idx = (left_idx + right_idx) / 2;
        Node left_val = Update(target_idx, val, cur_idx * 2, left_idx, mid_idx);
        Node right_val = Update(target_idx, val, cur_idx * 2 + 1, mid_idx + 1, right_idx);
        range_sum[cur_idx].sum = left_val.sum + right_val.sum;
        range_sum[cur_idx].l_sum = max(left_val.l_sum, left_val.sum + right_val.l_sum);
        range_sum[cur_idx].r_sum = max(right_val.r_sum, left_val.r_sum + right_val.sum);
        range_sum[cur_idx].max_partial_sum = max(max(left_val.max_partial_sum, right_val.max_partial_sum), left_val.r_sum + right_val.l_sum);

        return range_sum[cur_idx];
    }

private:
    int arr_size;
    int U;
    int V;
    // {전체 합, 왼쪽값 포함 최대 부분합, 오른쪽값 포함 최대 부분합, 구간 전체 최대 부분합}
    vector<Node> range_sum;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q, U, V, C, A, B;
    cin >> N >> Q >> U >> V;

    vector<int> k_vec(N, 0);
    
    for(int i=0; i < N; i++) {
        cin >> k_vec[i];
    }

    SegTree tree(k_vec, N, U, V);

    for(int i=0; i < Q; i++) {
        cin >> C >> A >> B;
        if(C == 0) {
            cout << tree.Sum(A - 1, B - 1).max_partial_sum - V << '\n';
        } else {
            tree.Update(A - 1, B);
        }
    }

}