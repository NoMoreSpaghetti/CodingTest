#include <iostream>
using namespace std;

int N, M, K;
long long ary[1000000];
long long tree[3000001] = {0};

long long init_tree(int start, int end, int node) {
    if(start == end) {
        return tree[node] = ary[start];
    } else {
        int mid = (start + end) / 2;
        return tree[node] = init_tree(start, mid, node * 2) + init_tree(mid + 1, end, node * 2 + 1);
    }
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

    int a;
    long long b, c;
    cin >> N >> M >> K;
    for(int i=0; i < N; i++) {
        cin >> ary[i];
    }

    init_tree(0, N - 1, 1);

    for(int j=0; j < M + K; j++) {
        cin >> a >> b >> c;
        if(a == 1) {
            update(0, N - 1, 1, b - 1, c - ary[b - 1]);
            ary[b - 1] = c;
        } else {
            cout << get_sum(0, N - 1, 1, b - 1, c - 1) << '\n';
        }
    }
}