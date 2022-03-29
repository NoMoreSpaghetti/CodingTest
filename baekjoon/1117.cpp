#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long W, H, f, c, x1, y1, x2, y2;
    cin >> W >> H >> f >> c >> x1 >> y1 >> x2 >> y2;

    if(f * 2 > W) {
        f = W - f;
    }

    long long filled = 0;
    if(f > x1) {
        filled += (y2 - y1) * (min(f, x2) - x1) * ((c + 1) * 2);
    }
    if(x2 > f) {
        filled += (y2 - y1) * (x2 - max(f, x1)) * (c + 1);
    }

    cout << W * H - filled << '\n';
}