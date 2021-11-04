#include <iostream>
using namespace std;

short board[9][9] = {0};
int h[9] = {0};
int v[9] = {0};
int cube[9] = {0};
int zeros[81][2] = {0};
int zero_num = 0;

int num_to_bit(int num) {
    return 1 << (num - 1);
}

bool sudoku(int idx) {
    if(idx == zero_num) {
        return true;
    }

    int y = zeros[idx][0];
    int x = zeros[idx][1];
    int cube_idx = (y / 3) * 3 + (x / 3);
    int bit = h[y] | v[x] | cube[cube_idx];
    int i_bit = 1;
    for(int i=1; i <= 9; i++) {
        if((bit & i_bit) == 0) {
            board[y][x] = i;
            h[y] |= i_bit;
            v[x] |= i_bit;
            cube[cube_idx] |= i_bit;
            if(sudoku(idx + 1)) {
                return true;
            }
            board[y][x] = 0;
            h[y] ^= i_bit;
            v[x] ^= i_bit;
            cube[cube_idx] ^= i_bit;
        }
        i_bit <<= 1;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0; i < 9; i++) {
        for(int j=0; j < 9; j++) {
            cin >> board[i][j];
            if(board[i][j] == 0) {
                zeros[zero_num][0] = i;
                zeros[zero_num][1] = j;
                zero_num++;
            } else {
                int bit = num_to_bit(board[i][j]);
                h[i] |= bit;
                v[j] |= bit;
                cube[(i / 3) * 3 + (j / 3)] |= bit;
            }
        }
    }

    sudoku(0);

    for(int i=0; i < 9; i++) {
        for(int j=0; j < 9; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}