// 참고: https://degurii.tistory.com/158

#include <iostream>
using namespace std;

long long ary[60] = {0};

long long get_num_1_by_idx(int idx) {
    return ((long long)1 << (idx - 1)) * idx;
}

long long my_func(long long n) {
    int cnt = 0;
    long long temp_n = n;
    while(temp_n > 0) {
        temp_n >>= 1;
        cnt++;
    }
    cnt--;

    long long ans = n & 1;
    for(int i=cnt; i > 0; i--) {
        long long cur_num_mask = ((long long)1 << i);
        if((n & cur_num_mask) > 0) {
            
            ans += ary[i - 1] + (n - cur_num_mask + 1);
            n -= cur_num_mask;
        }
    }

    return ans;
}

int main() {
    long long A, B;
    cin >> A >> B;
    ary[0] = 1;

    for(int i=1; i < 60; i++) {
        ary[i] = ary[i - 1] * 2 + ((long long)1 << i);
    }

    cout << my_func(B) - my_func(A - 1) << '\n';
}