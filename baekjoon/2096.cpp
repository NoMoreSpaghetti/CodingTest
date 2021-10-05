#include <iostream>
using namespace std;

int N;
int board[100000][3];

int get_max_score() {
    int a_0 = board[0][0];
    int a_1 = board[0][1];
    int a_2 = board[0][2];

    int b_0, b_1, b_2;

    for(int n=1; n < N; n++) {
        b_0 = max(a_0, a_1) + board[n][0];
        b_1 = max(max(a_0, a_1), a_2) + board[n][1];
        b_2 = max(a_1, a_2) + board[n][2];
        a_0 = b_0;
        a_1 = b_1;
        a_2 = b_2;
    }

    return max(max(a_0, a_1), a_2);
}

int get_min_score() {
    int a_0 = board[0][0];
    int a_1 = board[0][1];
    int a_2 = board[0][2];

    int b_0, b_1, b_2;

    for(int n=1; n < N; n++) {
        b_0 = min(a_0, a_1) + board[n][0];
        b_1 = min(min(a_0, a_1), a_2) + board[n][1];
        b_2 = min(a_1, a_2) + board[n][2];
        a_0 = b_0;
        a_1 = b_1;
        a_2 = b_2;
    }

    return min(min(a_0, a_1), a_2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int n=0; n < N; n++) {
        for(int i=0; i < 3; i++) {
            cin >> board[n][i];
        }
    }

    cout << get_max_score() << ' ' << get_min_score() << '\n';
}