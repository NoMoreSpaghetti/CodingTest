#include <iostream>
#include <string.h>
using namespace std;

int R, C, T;
int room[50][50];
int dust_to_append[50][50];
int air_fresher[2];

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};


void move_air(int start_r, int start_c, int d_idx, int limit) {
    int cur_r = start_r;
    int cur_c = start_c;
    int next_r = start_r + dr[d_idx];
    int next_c = start_c + dc[d_idx];

    if(dr[d_idx] != 0) {
        if(dr[d_idx] > 0) {
            while(next_r <= limit) {
                room[cur_r][cur_c] = room[next_r][next_c];
                cur_r = next_r;
                next_r += dr[d_idx];
            }
        } else {
            while(next_r >= limit) {
                room[cur_r][cur_c] = room[next_r][next_c];
                cur_r = next_r;
                next_r += dr[d_idx];
            }
        }
    } else {
        if(dc[d_idx] > 0) {
            while(next_c <= limit) {
                room[cur_r][cur_c] = room[next_r][next_c];
                cur_c = next_c;
                next_c += dc[d_idx];
            }
        } else {
            while(next_c >= limit) {
                room[cur_r][cur_c] = room[next_r][next_c];
                cur_c = next_c;
                next_c += dc[d_idx];
            }
        }
    }
}

void run_air_fresher() {
    for(int t=0; t < T; t++) {
        memset(dust_to_append, 0, sizeof(dust_to_append));
        // 확산
        for(int r=0; r < R; r++) {
            for(int c=0; c < C; c++) {
                if(room[r][c] != -1) {
                    int num_separated_dust = room[r][c] / 5;
                    int num_separated = 4;
                    // 4 방향 확인 후 확산
                    for(int i=0; i < 4; i++) {
                        int next_r = r + dr[i];
                        int next_c = c + dc[i];
                        if((next_r < 0 || next_c < 0 || next_r >= R || next_c >= C) || room[next_r][next_c] == -1) {
                            num_separated--;
                            continue;
                        }
                        dust_to_append[next_r][next_c] += num_separated_dust;
                    }
                    room[r][c] -= num_separated_dust * num_separated;
                }
            }
        }

        for(int r=0; r < R; r++) {
            for(int c=0; c < C; c++) {
                room[r][c] += dust_to_append[r][c];
            }
        }

        // 순환
        // 순환 방향과 거꾸로 계산
        int air_r = air_fresher[0];
        int air_c = 0;
        move_air(air_r - 1, air_c, 2, 0);
        move_air(0, air_c, 1, C - 1);
        move_air(0, C - 1, 0, air_r);
        move_air(air_r, C - 1, 3, air_c + 1);
        room[air_r][air_c + 1] = 0;

        air_r = air_fresher[1];
        move_air(air_r + 1, air_c, 0, R - 1);
        move_air(R - 1, air_c, 1, C - 1);
        move_air(R - 1, C - 1, 2, air_r);
        move_air(air_r, C - 1, 3, air_c + 1);
        room[air_r][air_c + 1] = 0;
    }
}

int count_dust() {
    int sum = 0;
    for(int r=0; r < R; r++) {
        for(int c=0; c < C; c++) {
            sum += room[r][c];
        }
    }

    // 공기청정기가 2칸이고 값이 -1이므로 2를 더함
    sum += 2;

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> T;

    int air_fresher_point_idx = 0;
    for(int r=0; r < R; r++) {
        for(int c=0; c < C; c++) {
            cin >> room[r][c];
            if(room[r][c] == -1) {
                air_fresher[air_fresher_point_idx] = r;
                air_fresher_point_idx++;
            }
        }
    }

    run_air_fresher();

    cout << count_dust() << '\n';
}