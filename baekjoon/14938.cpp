#include <iostream>
#include <vector>
using namespace std;

int INF = 1500;
int n, m, r;
int items[101];
int v[101][101];
int dists[101][101];

void floyd_washall() {
    for(int i=1; i <= n; i++) {
        for(int j=1; j <= n; j++) {
            dists[i][j] = v[i][j];
        }
    }

    for(int k=1; k <= n; k++) {
        for(int i=1; i <= n; i++) {
            for(int j=1; j <= n; j++) {
                if(dists[i][k] + dists[k][j] < dists[i][j]) {
                    dists[i][j] = dists[i][k] + dists[k][j];
                }
            }
        }
    }
}

int get_max_num_item() {
    int max_num_item = 0;
    for(int i=1; i <= n; i++) {
        int num_item = 0;
        for(int j=1; j <= n; j++) {
            if(dists[i][j] <= m) {
                num_item += items[j];
            }
        }

        if(num_item > max_num_item) {
            max_num_item = num_item;
        }
    }
    return max_num_item;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, a, b, l;
    cin >> n >> m >> r;

    for(int i=1; i <= n; i++) {
        cin >> items[i];
    }

    fill(&v[0][0], &v[100][101], INF);    
    for(int i=0; i < r; i++) {
        cin >> a >> b >> l;
        v[a][b] = l;
        v[b][a] = l;
    }

    for(int i=1; i <= n; i++) {
        v[i][i] = 0;
    }

    floyd_washall();
    
    cout << get_max_num_item() << '\n';
}