#include <iostream>
using namespace std;

int n;
int in_order[100001];
int post_order[100001];
int root_idx_in_inorder[100001];

void print_pre_order(int left, int right, int post_order_right) {
    int root = post_order[post_order_right];
    if(right <= left) {
        return;
    } else if(right == left + 1) {
        cout << in_order[left] << ' ';
        return;
    }

    // find root index in inorder
    int i = root_idx_in_inorder[root];
    int right_size = right - i - 1;

    // recursive
    cout << root << ' ';
    print_pre_order(left, i, post_order_right - right_size - 1);
    print_pre_order(i + 1, right, post_order_right - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i=0; i < n; i++) {
        cin >> in_order[i];
        root_idx_in_inorder[in_order[i]] = i;
    }
    for(int i=0; i < n; i++) {
        cin >> post_order[i];
    }

    print_pre_order(0, n, n - 1);
}