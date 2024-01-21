#include <iostream>
#include <vector>
using namespace std;

vector<int> roots;
vector<int> ranks;

int find_root(int n) {
    if(roots[n] == n) {
        return n;
    }
    return roots[n] = find_root(roots[n]);
}

void my_union(int x, int y) {
    x = find_root(x);
    y = find_root(y);

    if(x == y) {
        return;
    }

    if(ranks[x] > ranks[y]) {
        roots[y] = x;
    } else {
        roots[x] = y;
        if(ranks[y] == ranks[x]) {
            ranks[x]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, connected, city;
    cin >> N >> M;

    // vector<vector<int>> connection = vector<vector<int>>(N, vector<int>(N, 0));
    roots = vector<int>(N, -1);
    ranks = vector<int>(N, 0);

    for(int i=0; i < N; i++) {
        roots[i] = i;
    }

    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            cin >> connected;
            if(connected) {
                my_union(i, j);
            }
        }
    }

    cin >> city;
    bool is_connected = true;
    int root = find_root(city - 1);
    for(int i=1; i < M; i++) {
        cin >> city;
        if(find_root(city - 1) != root) {
            is_connected = false;
        }
    }

    if(is_connected) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}