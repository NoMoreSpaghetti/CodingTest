#include <iostream>
#include <stack>
#include <tuple>
using namespace std;

int R, C, bit = 0, max_len = 0;
char board[20][20];

int alp_to_bit(char c) {
    return 1 << (c - 'A');
}

void dfs(int y, int x, int len) {
    if(y < 0 || y >= R || x < 0 || x >= C) {
        return;
    }
    int new_bit = alp_to_bit(board[y][x]);
    if((bit & new_bit) == 0) {
        bit = bit | new_bit;
        max_len = max(max_len, len);
        dfs(y, x + 1, len + 1);
        dfs(y + 1, x, len + 1);
        dfs(y, x - 1, len + 1);
        dfs(y - 1, x, len + 1);
        bit ^= new_bit;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    for(int i=0; i < R; i++) {
        for(int j=0; j < C; j++) {
            cin >> board[i][j];
        }
    }

    dfs(0, 0, 1);

    cout << max_len << '\n';
}