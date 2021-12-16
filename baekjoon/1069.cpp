#include <iostream>
#include <math.h>
#include <limits>
using namespace std;

int X, Y, D, T;

double get_dist(int x, int y) {
    return sqrt(x * x + y * y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> X >> Y >> D >> T;

    double dist = get_dist(X, Y);

    double ans = 0;
    // 점프가 걷는거보다 느릴 경우
    if(T >= D) {
        ans = dist;
    } else {
        // 점프가 남은 거리보다 길 경우
        if(D > dist) {
            // 점프 두 번 vs 점프 한 번 후 이동 vs 이동
            ans = min(min(2.0 * T, D - dist + T), dist);
        } else {
            // 두 번 이하로 점프할 수 있는 거리까지 점프
            while(dist > 2 * D) {
                dist -= D;
                ans += T;
            }

            // 점프 한 번 하고 이동
            if(T > dist - D) {
                ans += dist - D + T;
            } else { // 점프 두 번으로 도착
                ans += 2 * T;
            }
        }
    }


    cout.precision(numeric_limits<double>::max_digits10);
    cout << ans << '\n';
}