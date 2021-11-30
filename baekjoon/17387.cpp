#include <iostream>
#define SWAP(a, b) do {int temp = a; a = b; b = temp;} while(0);
using namespace std;

int x1, y1, x2, y2, x3, y3, x4, y4;

int ccw(pair<int, int> start_p, pair<int, int> p1, pair<int, int> p2) {
    long long ccw_val = (p1.first - start_p.first) * (long long)(p2.second - start_p.second) -
                        (p1.second - start_p.second) * (long long)(p2.first - start_p.first);
    if(ccw_val == 0) {
        return 0;
    } else if(ccw_val > 0) {
        return 1;
    } else {
        return -1;
    }
}

bool larger(pair<int, int> p1, pair<int, int>p2) {
    // if p1.first is larger than p2.first, return true
    // else if p1.first == p2.first, return p1.second >= p2.second
    if(p1.first > p2.first) {
        return true;
    } else if(p1.first == p2.first) {
        return (p1.second >= p2.second);
    } else {
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    pair<int, int> p1 = {x1, y1};
    pair<int, int> p2 = {x2, y2};
    pair<int, int> p3 = {x3, y3};
    pair<int, int> p4 = {x4, y4};

    int ccw_v12_p3 = ccw(p1, p2, p3);
    int ccw_v12_p4 = ccw(p1, p2, p4);
    int ccw_v34_p1 = ccw(p3, p4, p1);
    int ccw_v34_p2 = ccw(p3, p4, p2);

    int ccw_v12_v34 = ccw_v12_p3 * ccw_v12_p4;
    int ccw_v34_v12 = ccw_v34_p1 * ccw_v34_p2;

    int ans = 0;

    if(ccw_v12_v34 == 0 && ccw_v34_v12 == 0) {
        if(larger(p1, p2)) {
            SWAP(p1.first, p2.first);
            SWAP(p1.second, p2.second);
        }
        if(larger(p3, p4)) {
            SWAP(p3.first, p4.first);
            SWAP(p3.second, p4.second);
        }
        if(larger(p4, p1) && larger(p2, p3)) {
            ans = 1;
        } else if(larger(p2, p3) && larger(p4, p1)) {
            ans = 1;
        }
    } else {
        ans = (ccw_v12_v34 <= 0) && (ccw_v34_v12 <= 0);
    }
    cout << ans << '\n';
}