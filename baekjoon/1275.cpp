// 참고: https://blog.naver.com/ndb796/221282210534

#include <iostream>
using namespace std;

int N, Q;
long long ary[100000];
long long tree[900001] = {0};

long long init_seg_tree(int start, int end, int node) {
    if(start == end) {
        return tree[node] = ary[start];
    }
    int mid = (start + end) / 2;
    return tree[node] = init_seg_tree(start, mid, node * 2) + init_seg_tree(mid + 1, end, node * 2 + 1);
}

long long get_sum(int start, int end, int node, int left, int right) {
    if(left > end || right < start) {
        return 0;
    } else if(left <= start && end <= right) {
        return tree[node];
    } else {
        int mid = (start + end) / 2;
        return get_sum(start, mid, node * 2, left, right) + get_sum(mid + 1, end, node * 2 + 1, left, right);
    }
}

void update(int start, int end, int node, int idx, long long dif) {
    if(idx < start || idx > end) {
        return;
    } else {
        tree[node] += dif;
        if(start == end) {
            return;
        } else {
            int mid = (start + end) / 2;
            update(start, mid, node * 2, idx, dif);
            update(mid + 1, end, node * 2 + 1, idx, dif);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y, a;
    long long b;
    cin >> N >> Q;
    for(int i=0; i < N; i++) {
        cin >> ary[i];
    }

    init_seg_tree(0, N - 1, 1);

    for(int i=0; i < Q; i++) {
        cin >> x >> y >> a >> b;
        if(y >= x) {
            cout << get_sum(0, N - 1, 1, x - 1, y - 1) << '\n';
        } else {
            cout << get_sum(0, N - 1, 1, y - 1, x - 1) << '\n';
        }
        update(0, N - 1, 1, a - 1, b - ary[a - 1]);
        ary[a - 1] = b;
    }
}