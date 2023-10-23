#include <iostream>
#include <vector>
using namespace std;

int n, m;

int root[500000];
int node_rank[500000] = {0};

int find_root(int x) {
    if(root[x] == x) {
        return x;
    } else {
        int r = find_root(root[x]);
        root[x] = r;
        return root[x];
    }
}

bool my_union(int x, int y) {
    x = find_root(x);
    y = find_root(y);

    if(x == y) {
        return true;
    } else {
        if(node_rank[x] < node_rank[y]) {
            root[x] = y;
        } else {
            root[y] = x;

            if(node_rank[x] == node_rank[y]) {
                node_rank[x]++;
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i=0; i < n; i++) {
        root[i] = i;
    }

    int x, y;
    bool cycle_exists = false;
    for(int i=0; i < m; i++) {
        cin >> x >> y;
        if(!cycle_exists && my_union(x, y)) {
            cycle_exists = true;
            cout << i + 1 << '\n';
        }
    }

    if(!cycle_exists) {
        cout << 0 << '\n';
    }
}