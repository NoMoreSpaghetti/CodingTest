#include <iostream>
#include <vector>
using namespace std;

int N, M;

typedef long long ll;

class SegTree {
public:
    SegTree(int arr_size)
    : range_sum(arr_size * 4, 0), arr_size(arr_size)
    {
    }

    ll Sum(int left, int right) {
        return Sum(left, right, 1, 0, arr_size - 1);
    }

    ll Sum(int left, int right, int cur_idx, int left_idx, int right_idx) {
        if(left <= left_idx && right >= right_idx) {
            return range_sum[cur_idx];
        }

        if(left > right_idx || right < left_idx) {
            return 0;
        }

        int mid_idx = (left_idx + right_idx) / 2;
        ll left_val = Sum(left, right, cur_idx * 2, left_idx, mid_idx);
        ll right_val = Sum(left, right, cur_idx * 2 + 1, mid_idx + 1, right_idx);
        return left_val + right_val;
    }

    void Modify(int pos, int val) {
        Modify(pos, val, 1, 0, arr_size - 1);
    }

    ll Modify(int pos, int val, int cur_idx, int left_idx, int right_idx) {
        if(pos < left_idx || pos > right_idx) {
            return range_sum[cur_idx];
        }
        if(left_idx == right_idx) {
            return range_sum[cur_idx] = static_cast<ll>(val);
        }

        int mid_idx = (left_idx + right_idx) / 2;
        ll left_val = Modify(pos, val, cur_idx * 2, left_idx, mid_idx);
        ll right_val = Modify(pos, val, cur_idx * 2 + 1, mid_idx + 1, right_idx);
        return range_sum[cur_idx] = left_val + right_val;
    }

private:
    int arr_size;
    vector<ll> range_sum;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    int op, a, b;

    SegTree tree(N);

    while(M--) {
        cin >> op >> a >> b;
        if(op == 0) {
            if(a > b) swap(a, b);
            cout << tree.Sum(a - 1, b - 1) << '\n';
        } else {
            tree.Modify(a - 1, b);
        }
    }
}