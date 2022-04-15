#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct RMQ {
    int n;
    vector<pair<int, int>> vec;
    RMQ(const vector<int>& array) {
        n = array.size();
        vec.resize(n * 4);
        init(array, 0, n - 1, 1);
    }

    pair<int, int> init(const vector<int>& array, int left, int right, int node) {
        if(left == right) {
            vec[node].first = array[left];
            vec[node].second = array[left];
            return vec[node];
        }
        int mid = (left + right) / 2;
        pair<int, int> leftVal = init(array, left, mid, node * 2);
        pair<int, int> rightVal = init(array, mid + 1, right, node * 2 + 1);
        vec[node].first = min(leftVal.first, rightVal.first);
        vec[node].second = max(leftVal.second, rightVal.second);
        return vec[node];
    }

    int min_query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if(right < nodeLeft || nodeRight < left) {
            return INT_MAX;
        } else if(left <= nodeLeft && nodeRight <= right) {
            return vec[node].first;
        }

        int mid = (nodeLeft + nodeRight) / 2;
        return min(min_query(left, right, node * 2, nodeLeft, mid),
                   min_query(left, right, node * 2 + 1, mid + 1, nodeRight));
    }

    int max_query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if(right < nodeLeft || nodeRight < left) {
            return 0;
        } else if(left <= nodeLeft && nodeRight <= right) {
            return vec[node].second;
        }

        int mid = (nodeLeft + nodeRight) / 2;
        return max(max_query(left, right, node * 2, nodeLeft, mid),
                   max_query(left, right, node * 2 + 1, mid + 1, nodeRight));
    }

    int min_query(int left, int right) {
        return min_query(left, right, 1, 0, n - 1);
    }

    int max_query(int left, int right) {
        return max_query(left, right, 1, 0, n - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, a, b;
    cin >> N >> M;
    vector<int> vec(N);

    for(int i=0; i < N; i++) {
        cin >> vec[i];
    }

    RMQ rmq(vec);

    for(int i=0; i < M; i++) {
        cin >> a >> b;
        cout << rmq.min_query(a - 1, b - 1) << ' ' << rmq.max_query(a - 1, b - 1) << '\n';
    }
}