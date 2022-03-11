#include <iostream>
#include <vector>
using namespace std;

int N, M;
int board[9][9] = {0};
vector<int> square_vec;

bool binary_search(vector<int>& vec, int num) {
    int low = 0;
    int high = vec.size() - 1;
    int mid;
    
    while(low <= high) {
        mid = (low + high) / 2;
        if(vec[mid] == num) {
            return true;
        } else if(vec[mid] > num) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return false;
}

void update_square_vec() {
    int num = 1;
    int square = 0;
    int square_border = 1;
    int max_len = (((N > M) ? N : M));
    for(int i=0; i < max_len; i++) {
        square_border *= 10;
    }
    while(square < square_border) {
        square_vec.push_back(square);
        square = num * num;
        num++;
    }
}

int get_largest_square() {
    int largest_square = -1;

    for(int r=0; r < N; r++) {
        for(int c=0; c < M; c++) {
            if(binary_search(square_vec, board[r][c])) {
                if(largest_square < board[r][c]) {
                    largest_square = board[r][c];
                }
            }
            for(int i=-r; i < (N - r); i++) {
                for(int j=-c; j < (M - c); j++) {
                    if(i == 0 && j == 0) {
                        continue;
                    }

                    int num = board[r][c];
                    int next_r = r + i;
                    int next_c = c + j;

                    while(!(next_r < 0 || next_r >= N || next_c < 0 || next_c >= M)) {
                        num = num * 10 + board[next_r][next_c];
                        if(binary_search(square_vec, num)) {
                            if(largest_square < num) {
                                largest_square = num;
                            }
                        }
                        next_r += i;
                        next_c += j;
                    }
                }
            }
        }
    }

    return largest_square;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    char inp;
    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            cin >> inp;
            board[i][j] = inp - '0';
        }
    }

    update_square_vec();
    cout << get_largest_square() << '\n';

    return 0;
}