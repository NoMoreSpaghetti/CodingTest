#include <iostream>
using namespace std;

int G, P;
int roots[100001] = {0};
int g_ary[100001] = {0};

int find_root(int plane) {
    if(roots[plane] == plane) {
        return plane;
    } else {
        return roots[plane] = find_root(roots[plane]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> G >> P;

    for(int g=1; g <= G; g++) {
        roots[g] = g;
    }

    for(int p=1; p <= P; p++) {
        cin >> g_ary[p];
    }

    int ans = 0;
    for(int i=1; i <= P; i++) {
        int p = find_root(g_ary[i]);
        if(p == 0) {
            break;
        }
        roots[p] = p - 1;
        ans++;
    }

    cout << ans << '\n';
}