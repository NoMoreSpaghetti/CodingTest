#include <iostream>
using namespace std;

int D;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> D;

    long long left = 0;
    long long right = 1;

    while(right * right < D) {
        right++;
    }

    bool valid = false;

    while(right * right - (right - 1) * (right - 1) <= D) {
        long long val = right * right - left * left;
        if(val < D) {
            right++;
        } else if(val > D) {
            left++;
        } else {
            valid = true;
            break;
        }
    }
    if(valid) {
        cout << left << ' ' << right << '\n';
    } else {
        cout << "impossible" << '\n';
    }
}