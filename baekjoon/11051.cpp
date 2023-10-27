#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<vector<int>> cache(N + 1, vector<int>(K + 1, 0));
    for(int i=0; i <= N; i++) {
        if(i <= K) {
            cache[i][i] = 1;
        }
        cache[i][0] = 1;
    }

    for(int i=1; i <= N; i++) {
        for(int j=1; j <= min(i - 1, K); j++) {
            cache[i][j] = (cache[i - 1][j - 1] + cache[i - 1][j]) % 10007;
        }
    }

    cout << cache[N][K] << '\n';
}