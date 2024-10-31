#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x, y, z;
};

double GetSquare(Point A, Point B) {
    return pow(B.x - A.x, 2) + pow(B.y - A.y, 2) + pow(B.z - A.z, 2);
}

double GetDist(Point A, Point B) {
    return sqrt(GetSquare(A, B));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double x, y, z;
    
    cin >> x >> y >> z;
    Point A{x, y, z};
    cin >> x >> y >> z;
    Point B{x, y, z};
    cin >> x >> y >> z;
    Point C{x, y, z};
    
    double sq_ab = GetSquare(A, B);
    double sq_bc = GetSquare(B, C);
    double sq_ac = GetSquare(A, C);

    double ans = 0;

    if(sq_bc > sq_ab + sq_ac) {
        ans = sqrt(sq_ac);
    } else if(sq_ac > sq_ab + sq_bc) {
        ans = sqrt(sq_bc);
    } else {
        double s = (sqrt(sq_ab) + sqrt(sq_bc) + sqrt(sq_ac)) / 2;
        double d_ab = sqrt(sq_ab);
        double d_bc = sqrt(sq_bc);
        double d_ac = sqrt(sq_ac);
        ans = sqrt(s * (s - d_ab) * (s - d_bc) * (s - d_ac)) / d_ab * 2;
    }

    cout.precision(12);
    cout << ans << '\n';
}