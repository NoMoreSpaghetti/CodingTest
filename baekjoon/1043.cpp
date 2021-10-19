// 참고
// https://gmlwjd9405.github.io/2018/08/31/algorithm-union-find.html

#include <iostream>
using namespace std;

int root[51];
int node_rank[51];

int my_find(int x) {
    if(root[x] == x) {
        return x;
    } else {
        int r = my_find(root[x]);
        if(r == 0) {
            root[x] = 0;
        } else {
            root[x] = r;
        }
        return root[x];
    }
}

void my_union(int x, int y) {
    x = my_find(x);
    y = my_find(y);

    if(x == y) {
        return;
    }

    if(x == 0) {
        root[y] = 0;
    } else if(y == 0) {
        root[x] = 0;
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
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0; i < 51; i++) {
        root[i] = i;
        node_rank[i] = 0;
    }

    int N, M, NT, NP, root_node, tmp;
    int first_of_party[51];
    cin >> N >> M;

    cin >> NT;
    for(int i=0; i < NT; i++) {
        cin >> tmp;
        root[tmp] = 0;
    }

    for(int m=1; m <= M; m++) {
        cin >> NP;
        cin >> root_node;
        first_of_party[m] = root_node;
        for(int i=1; i < NP; i++) {
            cin >> tmp;
            my_union(tmp, root_node);
        }
    }

    int cnt = 0;
    for(int m=1; m <= M; m++) {
        if(my_find(first_of_party[m]) != 0) {
            cnt++;
        }
    }

    cout << cnt << '\n';
}