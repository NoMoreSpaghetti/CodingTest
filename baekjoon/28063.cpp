#include <iostream>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int x, y;
    cin >> x >> y;

    int ans = 4;
    if(x == 1 || x == N || y == 1 || y == N) ans = 3;
    if((x == 1 && y == 1) || (x == N && y == N) || (x == 1 && y == N) || (x == N && y == 1)) ans = 2;
    if(N == 1) ans = 0;

    cout << ans << '\n';
}