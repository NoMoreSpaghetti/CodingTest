#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, type;
    double a, b;
    cin >> T;
    while(T--) {
        cin >> type >> a >> b;
        cout.precision(9);

        if(type == 1) {
            double theta = 0;
            if(a > 0 && b >= 0) {
                theta = atan(b / a);
            } else if(a > 0 && b < 0) {
                theta = atan(b / a) + 2 * M_PI;
            } else if(a < 0) {
                theta = atan(b / a) + M_PI;
            } else if(a == 0 && b > 0) {
                theta = M_PI / 2;
            } else if(a == 0 && b < 0) {
                theta = M_PI * 3 / 2;
            }

            cout << sqrt(a * a + b * b) << ' ' << theta << '\n';
        } else {
            cout << cos(b) * a << ' ' << sin(b) * a << '\n';
        }
    }
}