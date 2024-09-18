#include <iostream>
using namespace std;

// 빨강: 1, 파랑: 2, 노랑: 3
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, x, y;
    cin >> N >> K;

    for(int i=0; i < K; i++) {
        cin >> x >> y;
        x--;
        y--;
        x = min(x, N - x - 1);
        y = min(y, N - y - 1);
        int min_val = min(x, y);

        cout << min_val % 3 + 1 << '\n';
    }
}