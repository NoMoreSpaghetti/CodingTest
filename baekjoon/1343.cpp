#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string board, answer = "";
    cin >> board;

    int i = 0;
    int num_x = 0;
    bool available = true;
    while(i < board.length()) {
        if(board[i] == 'X') {
            num_x++;
        } else {
            if(num_x % 2 == 1) {
                available = false;
                break;
            } else if(num_x != 0) {
                answer += "BB";
            }
            num_x = 0;
            answer += '.';
        }

        if(num_x == 4) {
            answer += "AAAA";
            num_x = 0;
        }

        i++;
    }

    if(num_x % 2 == 1) {
        available = false;
    } else if(num_x != 0) {
        answer += "BB";
    }

    if(available) {
        cout << answer << '\n';
    } else {
        cout << -1 << '\n';
    }
}