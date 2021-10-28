// 참고: https://blog.naver.com/ndb796/221234427842

#include <iostream>
using namespace std;

int DIST_INF = 10000001;
int n, m;
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    fill(&v[0][0], &v[100][101], DIST_INF);

    int a, b, c;
    for(int i=0; i < m; i++) {
        cin >> a >> b >> c;
        if(c < v[a][b]) {
            v[a][b] = c;
        }
    }

    for(int i=1; i <= n; i++) {
        v[i][i] = 0;
    }

    floyd_washall();

    for(int i=1; i <= n; i++) {
        for(int j=1; j <= n; j++) {
            if(dists[i][j] == DIST_INF) {
                cout << 0 << ' ';
            } else {
                cout << dists[i][j] << ' ';
            }
        }
        cout << '\n';
    }
}