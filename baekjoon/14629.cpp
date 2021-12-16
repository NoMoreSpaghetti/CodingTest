#include <iostream>
#include <limits.h>
using namespace std;

string s;
long long N = 0;
long long dp[10];

long long recursive(int n, int bit, long long val) {
    if(n == s.length()) {
        return val;
    }
    int nth_bit = (1 << (s[n] - '0'));
    long long min_sub_val = abs(N - val);
    long long min_v = val;
    for(int i=0; i < 10; i++) {
        if(!(bit & (1 << i))) {
            long long v = recursive(n + 1, bit | (1 << i), val * 10 + i);
            long long sub_val = abs(N - v);
            if(sub_val < min_sub_val) {
                min_sub_val = sub_val;
                min_v = v;
            }
        }
    }
    return min_v;
}

long long get_ans() {
    if(s.length() > 10) {
        return 9876543210;
    } else {
        long long min_sub_val = LLONG_MAX;
        long long min_v = 0;
        for(int i=1; i < 10; i++) {
            long long v = recursive(1, (1 << i), i);
            long long sub_val = abs(N - v);
            if(sub_val < min_sub_val) {
                min_sub_val = sub_val;
                min_v = v;
            } else if(sub_val == min_sub_val) {
                min_v = min(min_v, v);
            }
        }
        return min_v;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    for(int i=0; i < s.length(); i++) {
        N = N * 10 + (s[i] - '0');
    }

    cout << get_ans() << '\n';
}