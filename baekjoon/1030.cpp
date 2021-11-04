#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

char board[50][50];
int s, N, K, r1, r2, c1, c2;

int my_pow(int num, int count) {
    int result = 1;
    while(count > 0) {
        if((count & 1) == 1) {
            result *= num;
        }
        num *= num;
        count /= 2;
    }

    return result;
}

void recursive(int t, int n, int left, int right, int top, int bottom) {
    if(left > c2 || right < c1 || top > r2 || bottom < r1) {
        return;
    } else if(t == 0) {
        return;
    } else {
        int next_n = n / N;
        // fill center
        int border_size = (n - (K * next_n)) / 2;
        int c_left = left + border_size;
        int c_right = right - border_size;
        int c_top = top + border_size;
        int c_bottom = bottom - border_size;

        int min_right = min(c_bottom - r1, r2 - r1 + 1);
        int min_bottom = min(c_right - c1, c2 - c1 + 1);

        for(int i=max(c_top - r1, 0); i < min_right; i++) {
            for(int j=max(c_left - c1, 0); j < min_bottom; j++) {
                board[i][j] = '1';
            }
        }

        // fill except center
        for(int i=0; i < N; i++) {
            for(int j=0; j < N; j++) {
                if(i == j && i == N / 2) {
                    continue;
                }
                recursive(t - 1, next_n, left + i * next_n, right - (N - 1 - i) * next_n, top + j * next_n, bottom - (N - 1 - j) * next_n);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> N >> K >> r1 >> r2 >> c1 >> c2;

    memset(board, '0', sizeof(board));

    int start_n = my_pow(N, s);
    recursive(s, start_n, 0, start_n, 0, start_n);

    int height = r2 - r1;
    int width = c2 - c1;

    for(int i=0; i <= height; i++) {
        for(int j=0; j <= width; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}