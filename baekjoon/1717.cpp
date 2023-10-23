#include <iostream>
#include <vector>
using namespace std;

vector<int> ranks;
vector<int> roots;

int find_root(int n) {
    if(roots[n] == n) {
        return n;
    } else {
        return roots[n] = find_root(roots[n]);
    }
}

void my_union(int x, int y) {
    x = find_root(x);
    y = find_root(y);

    if(roots[x] == roots[y]) {
        return;
    } else if(ranks[x] > ranks[y]) {
        roots[y] = x;
    } else{
        roots[x] = y;
        if(ranks[x] == ranks[y]) {
            ranks[y]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, op, x, y;
    cin >> n >> m;

    ranks = vector<int>(n + 1, 0);
    for(int i=0; i <= n; i++) {
        roots.push_back(i);
    }

    while(m--) {
        cin >> op >> x >> y;
        if(op == 0) {
            my_union(x, y);
        } else {
            if(find_root(x) == find_root(y)) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }
}