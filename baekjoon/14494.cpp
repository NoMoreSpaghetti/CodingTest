#include<iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    const int div_num = 1000000007;
    cin >> n >> m;

    vector<vector<int>> D(n, vector<int>(m, 0));

    D[0][0] = 1;

    for(int i=0; i < n; i++) {
        D[i][0] = 1;
    }

    for(int i=0; i < m; i++) {
        D[0][i] = 1;
    }

    for(int i=1; i < n; i++) {
        for(int j=1; j < m; j++) {
            D[i][j] = (D[i - 1][j] + D[i][j - 1]) % div_num;
            D[i][j] = (D[i][j] + D[i - 1][j - 1]) % div_num;
        }
    }

    cout << D[n - 1][m - 1] << '\n';
}