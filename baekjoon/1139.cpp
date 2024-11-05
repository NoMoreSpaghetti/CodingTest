#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
vector<double> sides;
vector<double> areas;

double GetArea(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double Recursive(int bit, int start_idx) {
    double& ret = areas[bit];

    if(ret != -1) return ret;

    ret = 0;

    for(int i=start_idx; i < N; i++) {
        if(bit & (1 << i)) continue;

        for(int j=i + 1; j < N; j++) {
            if(bit & (1 << j)) continue;

            for(int k=j + 1; k < N; k++) {
                if(bit & (1 << k)) continue;

                if(sides[i] >= sides[j] + sides[k]) break; // 내림차순으로 정렬했으므로 다음 k번째 값은 현재 k번째 값보다 작다.

                int new_bit = bit | (1 << i) | (1 << j) | (1 << k);                
                double cur_area = GetArea(sides[i], sides[j], sides[k]);

                ret = max(ret, cur_area + Recursive(new_bit, i + 1));
            }
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    sides = vector<double>(N, 0);
    areas = vector<double>((1 << N), -1);

    for(int i=0; i < N; i++) {
        cin >> sides[i];
    }

    sort(sides.begin(), sides.end(), greater<double>());

    double ans = Recursive(0, 0);
    if(ans == -1) ans = 0;

    cout.precision(17);
    cout << ans << '\n';
}