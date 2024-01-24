#include <iostream>
#define pii pair<int, int>
using namespace std;

int ccw(const pii& p1, const pii& p2, const pii& p3) {
    int s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    s -= p1.second * p2.first + p2.second * p3.first + p3.second * p1.first;

    if(s > 0) {
        return 1;
    } else if(s == 0) {
        return 0;
    } else {
        return -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    pii points[4];
    for(int i=0; i < 4; i++) {
        cin >> points[i].first >> points[i].second;
    }

    if(ccw(points[0], points[1], points[2]) * ccw(points[0], points[1], points[3]) < 0) {
        cout << 1;
    } else {
        cout << 0;
    }

}