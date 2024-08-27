#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<LL, LL>> board(N, {0, 0});

    LL num_people = 0;
    for(int i=0; i < N; i++) {
        cin >> board[i].first >> board[i].second;
        num_people += board[i].second;
    }

    sort(board.begin(), board.end());

    LL threshold = (num_people + 1) / 2;
    LL sum = 0;
    for(int i=0; i < N; i++) {
        sum += board[i].second;
        if(sum >= threshold) {
            cout << board[i].first << '\n';
            break;
        }
    }
}