#include <iostream>
#include <vector>
using namespace std;

int find_root(vector<int>& roots, int x) {
    if(roots[x] == x) {
        return x;
    }

    return roots[x] = find_root(roots, roots[x]);
}

void my_union(vector<int>& roots, vector<int>& node_ranks, int a, int b) {
    a = find_root(roots, a);
    b = find_root(roots, b);

    if(a == b) {
        return;
    } else if(node_ranks[a] > node_ranks[b]) {
        roots[b] = a;
    } else {
        roots[a] = b;
        if(node_ranks[a] == node_ranks[b]) {
            node_ranks[a]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, M, K, a, b, u, v;
    cin >> T;

    for(int t=0; t < T; t++) {
        cin >> N >> K;
        vector<int> roots(N, -1);
        vector<int> node_ranks(N, 0);
        for(int i=0; i < N; i++) {
            roots[i] = i;
        }

        for(int k=0; k < K; k++) {
            cin >> a >> b;
            my_union(roots, node_ranks, a, b);
        }

        cin >> M;
        cout << "Scenario " << t + 1 << ":\n";
        for(int m=0; m < M; m++) {
            cin >> u >> v;
            if(find_root(roots, u) == find_root(roots, v)) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
        cout << '\n';
    }
}