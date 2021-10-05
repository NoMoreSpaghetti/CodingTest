#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int board[8][8];
int virus_labs[10][2];
int lab_cnt = 0;
int empty_cnt = 0;
int ans = 0;

bool visited[8][8];

bool check_valid_point(int y, int x) {
    if(y >= 0 && x >= 0 && y < N && x < M) {
        if(board[y][x] == 0) {
            return true;
        }
    }
    return false;
}

int bfs() {
    int d_y[] = {-1, 1, 0, 0};
    int d_x[] = {0, 0, -1, 1};
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    int safe_zone_size = empty_cnt;

    for(int i=0; i < lab_cnt; i++) {
        q.push(make_pair(virus_labs[i][0], virus_labs[i][1]));
    }

    while(!q.empty()) {
        pair<int, int> point = q.front();
        q.pop();
        
        if(visited[point.first][point.second]) {
            continue;
        }
        safe_zone_size--;
        visited[point.first][point.second] = true;
        for(int j=0; j < 4; j++) {
            int next_y = point.first + d_y[j];
            int next_x = point.second + d_x[j];
            if(check_valid_point(next_y, next_x)) {
                q.push(make_pair(next_y, next_x));
            }
        }
    }

    return safe_zone_size + lab_cnt;
}

void set_wall() {
    int saved_board[8][8];
    int board_size = N * M;
    int* permutation = new int[board_size];
    memset(permutation, 0, sizeof(int) * board_size);

    permutation[board_size - 1] = 1;
    permutation[board_size - 2] = 1;
    permutation[board_size - 3] = 1;

    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            saved_board[i][j] = board[i][j];
        }
    }

    do {
        for(int i=0; i < N; i++) {
            for(int j=0; j < M; j++) {
                board[i][j] = saved_board[i][j];
            }
        }
        int cnt = 0;
        for(int i=0; i < board_size; i++) {
            if(permutation[i] == 1) {
                int y = (int)(i / M);
                int x = i % M;
                if(board[y][x] == 0) {
                    board[y][x] = 1;
                    cnt++;
                }
            }
        }
        if(cnt != 3) {
            continue;
        }
        int a = bfs();
        ans = max(ans, a);
    } while(next_permutation(permutation, permutation + board_size));

    delete[] permutation;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(board, 0, sizeof(board));

    cin >> N >> M;

    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            cin >> board[i][j];
            if(board[i][j] == 2) {
                virus_labs[lab_cnt][0] = i;
                virus_labs[lab_cnt][1] = j;
                lab_cnt++;
            } else if(board[i][j] == 0) {
                empty_cnt++;
            }
        }
    }
    empty_cnt -= 3;

    set_wall();

    cout << ans << '\n';
}