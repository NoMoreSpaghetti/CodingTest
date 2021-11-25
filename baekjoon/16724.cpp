#include <iostream>
using namespace std;

int N, M;
int roots[1000000];

int my_find(int num) {
    if(roots[num] == -1 || roots[num] == num) {
        return num;
    }
    return roots[num] = my_find(roots[num]);
}

bool simple_union(int new_x, int p) {
    p = my_find(p);
    roots[new_x] = p;
    if(p == new_x) {
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(roots, roots + 1000000, -1);
    char inp;
    int ans = 0;
    cin >> N >> M;
    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            int cur_idx = i * M + j;
            cin >> inp;
            switch(inp) {
                case 'U':
                    if(simple_union(cur_idx, cur_idx - M)) {
                        ans++;
                    }
                    break;
                case 'D':
                    roots[cur_idx] = cur_idx + M;
                    break;
                case 'L':
                    if(simple_union(cur_idx, cur_idx - 1)) {
                        ans++;
                    }
                    break;
                case 'R':
                    roots[cur_idx] = cur_idx + 1;
                    break;
            }
        }
    }

    cout << ans << '\n';
}