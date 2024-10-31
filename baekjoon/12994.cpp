#include <iostream>
#include <cmath>
using namespace std;

long long x, y;

bool Recursive(long long interval, long long cur_x, long long cur_y) {
    if(interval <= 0) {
        if(cur_x == 0 && cur_y == 0) {
            return true;
        }
        return false;
    }

    long long next_interval = interval / 3;

    bool return_val = false;

    if(cur_x > 0) {
        return_val |= Recursive(next_interval, cur_x - interval, cur_y);
    } else if(cur_x < 0) {
        return_val |= Recursive(next_interval, cur_x + interval, cur_y);
    }

    if(cur_y > 0) {
        return_val |= Recursive(next_interval, cur_x, cur_y - interval);
    } else if(cur_y < 0) {
        return_val |= Recursive(next_interval, cur_x, cur_y + interval);
    }

    return return_val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x >> y;

    int ans = 1;
    if(!(x == 0 && y == 0)) {
        // 최대 간격을 먼저 구하고
        // x 또는 y에 더하거나 빼면서 0, 0으로 만들기
        // 가능하면 1 출력

        long long start_interval = 3;
        long long max_val = max(abs(x), abs(y));

        while(start_interval < max_val) {
            start_interval *= 3;
        }

        ans = Recursive(start_interval, x, y) ? 1 : 0;
        if(ans == 0) {
            ans = Recursive(start_interval / 3, x, y) ? 1 : 0;
        }
    }

    cout << ans << '\n';
}