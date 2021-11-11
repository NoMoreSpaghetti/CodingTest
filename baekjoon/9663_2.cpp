// 참고: https://www.acmicpc.net/source/35187108

#include <iostream>
#include <string.h>
using namespace std;

int N;
bool col[15], d_left[30], d_right[30];
int ans = 0;

void recursive(int num_q) {
    if(num_q == 0) {
        ans++;
        return;
    }

    int v_num = N - num_q;

    for(int i=0; i < N; i++) {
        int d_left_idx = i + num_q;
        int d_right_idx = N - 1 - i + num_q;
        if(col[i] == false && d_left[d_left_idx] == false && d_right[d_right_idx] == false) {
            col[i] = d_left[d_left_idx] = d_right[d_right_idx] = true;
            recursive(num_q - 1);
            col[i] = d_left[d_left_idx] = d_right[d_right_idx] = false;
        }
    }
}

int main() {
    memset(col, false, sizeof(col));
    memset(d_left, false, sizeof(d_left));
    memset(d_right, false, sizeof(d_right));

    cin >> N;

    recursive(N);

    cout << ans << '\n';
}