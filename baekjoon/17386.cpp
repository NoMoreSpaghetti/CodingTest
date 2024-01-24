#include <iostream>
#include <vector>
#define pll pair<long long, long long>
using namespace std;

int ccw(const pll& p1, const pll& p2, const pll& p3) {
    long long s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    s -= p1.second * p2.first + p2.second * p3.first + p3.second * p1.first;

    if(s > 0) {
        // 시계방향
        return 1;
    } else if(s == 0) {
        // 평행 또는 일직선
        return 0;
    } else {
        // 반시계 방향
        return -1;
    }
}

int is_intersect(const pair<pll, pll>& l1, const pair<pll, pll>& l2) {
    pll p1 = l1.first;
    pll p2 = l1.second;
    pll p3 = l2.first;
    pll p4 = l2.second;
    // 곱해서 음수면 교차
    // 양수면 교차하지 않음
    int l1_s = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int l2_s = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    // 세 점이 일직선 위에 있는 경우는 없다.
    // // 값이 둘 다 0이면 평행 or 일직선
    // // 하나만 0이면 끝점에서 만나는 경우
    // if(l1_s == 0 && l2_s == 0) {
    //     // pair을 비교하는 경우
    //     // 첫 번째 원소를 먼저 비교하고
    //     // 같으면 두 번째 원소로 비교
    //     if(p1 > p2) {
    //         swap(p1, p2);
    //     }
    //     if(p3 > p4) {
    //         swap(p3, p4);
    //     }
    //     // p2 >= p1이고 p4 >= p3인 상태
    //     // p2가 p3보다 크고 p4가 p1보다 큰 경우 겹친 상태
    //     // line1이 왼쪽이든 line2가 왼쪽이든 이 조건은 같음
    //     return p3 <= p2 && p1 <= p4;
    // }
    return l1_s <= 0 && l2_s <= 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pll points[4];

    for(auto& p : points) {
        cin >> p.first >> p.second;
    }
    
    if(is_intersect({points[0], points[1]}, {points[2], points[3]})) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }
}