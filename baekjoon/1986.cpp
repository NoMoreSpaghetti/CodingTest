#include <iostream>
#include <vector>
using namespace std;

enum CHESS_PIECE {
    KNIGHT = 2,
    QUEEN = 3,
    PAWN = 4
};

bool check_on_board(int n, int m, int y, int x) {
    if(y < 1 || y > n || x < 1 || x > m) {
        return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, num, x, y;
    vector<pair<int, int>> knight_movements = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},
                                               {1, 2}, {2, 1}, {2, -1}, {1, -2}};
    vector<pair<int, int>> queen_movements = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, 
                                              {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
    cin >> n >> m;
    vector<vector<int>> board(n + 1, vector<int>(m + 1, 0));
    vector<pair<int, int>> queens;

    cin >> num;
    for(int i=0; i < num; i++) {
        cin >> y >> x;
        board[y][x] = QUEEN;
        queens.push_back({y, x});
    }

    cin >> num;
    for(int i=0; i < num; i++) {
        cin >> y >> x;
        board[y][x] = KNIGHT;
        for(int j=0; j < knight_movements.size(); j++) {
            int candidate_y = y + knight_movements[j].first;
            int candidate_x = x + knight_movements[j].second;
            if(check_on_board(n, m, candidate_y, candidate_x)) {
                if(board[candidate_y][candidate_x] == 0) {
                    board[candidate_y][candidate_x] = -1;
                }
            }
        }
    }

    cin >> num;
    for(int i=0; i < num; i++) {
        cin >> y >> x;
        board[y][x] = PAWN;
    }

    for(int i=0; i < queens.size(); i++) {
        y = queens[i].first;
        x = queens[i].second;
        for(int j=0; j < queen_movements.size(); j++) {
            int candidate_y = y + queen_movements[j].first;
            int candidate_x = x + queen_movements[j].second;
            while(check_on_board(n, m, candidate_y, candidate_x)) {
                if(board[candidate_y][candidate_x] > 0) {
                    break;
                }
                if(board[candidate_y][candidate_x] == 0) {
                    board[candidate_y][candidate_x] = -1;
                }
                candidate_y += queen_movements[j].first;
                candidate_x += queen_movements[j].second;
            }
        }
    }

    int answer = 0;
    for(int i=1; i <= n; i++) {
        for(int j=1; j <= m; j++) {
            if(board[i][j] == 0) {
                answer++;
            }
        }
    }

    cout << answer << '\n';
}