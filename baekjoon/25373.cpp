#include <iostream>
using namespace std;

long long N;

long long GetMaxNumVids(long long start) {
    if(start >= 7) {
        return start * 7 - (7 * 6 / 2);
    }

    return (start * (start + 1) / 2);
}

long long BinarySearch(long long left, long long right) {
    long long return_val = __LONG_MAX__;
    while(left <= right) {
        long long mid = (left + right) / 2;
        long long num_vids = GetMaxNumVids(mid);

        if(num_vids >= N) {
            return_val = min(return_val, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return return_val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    // 방법 1.
    // 이분탐색

    // 방법 2.
    // x >= (N + 21) / 7
    // x = (N + 21 + 6) / 7 => 알아서 올림됨
    // N이 15보다 작을 경우, 조건분기 또는 이분탐색

    long long ans = 0;
    if(N <= 15) {
        ans = BinarySearch(1, 5);
    } else {
        ans = (N + 27) / 7;
    }

    cout << ans << '\n';
}