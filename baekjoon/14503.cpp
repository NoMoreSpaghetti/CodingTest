#include <iostream>
#include <vector>
using namespace std;

// 0: 북쪽, 1: 동쪽, 2: 남쪽, 3: 서쪽
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int N, M, r, c, d;

int clean_the_room(vector<vector<int>>& room) {
    int next_r, next_c;
    int num_cleaned_spaces = 0;

    while(true) {
        // 1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
        if(room[r][c] == 0) {
            room[r][c] = -1;
            num_cleaned_spaces++;
        }

        // 3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
        // 3-1. 반시계 방향으로 90도 회전한다.
        // 3-2. 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
        // 3-3. 1번으로 돌아간다.

        bool empty_space_exists = false;

        // 반시계 회전
        for(int i=0; i < 4; i++) {
            d = (d + 3) % 4;
            next_r = r + dy[d];
            next_c = c + dx[d];
            if(room[next_r][next_c] == 0) {
                r = next_r;
                c = next_c;
                empty_space_exists = true;
                break;
            }
        }
        
        // 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
        if(!empty_space_exists) {
            // 2-1. 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
            next_r = r + dy[(d + 2) % 4];
            next_c = c + dx[(d + 2) % 4];
            if(room[next_r][next_c] != 1) {
                r = next_r;
                c = next_c;
            } else {
                // 2-2. 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
                break;
            }
        }
    }

    return num_cleaned_spaces;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    cin >> r >> c >> d;

    vector<vector<int>> room = vector<vector<int>>(N, vector<int>(M, 0));
    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            cin >> room[i][j];
        }
    }

    cout << clean_the_room(room) << '\n';
}