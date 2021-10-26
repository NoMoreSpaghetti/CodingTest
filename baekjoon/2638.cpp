#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int N, M;
int my_map[100][100];
int values[100][100];
bool visited[100][100];

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

bool check_border(int y, int x) {
    if(y >= 0 && x >= 0 && y < N && x < M) {
        return true;
    }
    return false;
}

void bfs_to_set_outer_field() {
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    my_map[0][0] = 2;
    visited[0][0] = true;

    while(!q.empty()) {
        pair<int, int> here = q.front();
        q.pop();
        for(int i=0; i < 4; i++) {
            int new_y = here.first + dy[i];
            int new_x = here.second + dx[i];
            if(check_border(new_y, new_x)) {
                pair<int, int> there = make_pair(new_y, new_x);
                if(visited[new_y][new_x] == false) {
                    if(my_map[new_y][new_x] == 0) {
                        my_map[new_y][new_x] = 2;
                        q.push(there);
                    } else if(my_map[new_y][new_x] == 2) {
                        q.push(there);
                    }
                    visited[new_y][new_x] = true;
                }
            }
        }
    }
}

void get_after_1_hour() {
    for(int n=0; n < N; n++) {
        for(int m=0; m < M; m++) {
            if(my_map[n][m] == 1) {
                int num_air = 0;
                for(int i=0; i < 4; i++) {
                    int new_y = n + dy[i];
                    int new_x = m + dx[i];
                    if(check_border(new_y, new_x)) {
                        if(my_map[new_y][new_x] == 2) {
                            num_air++;
                        }
                    }
                }
                if(num_air >= 2) {
                    my_map[n][m] = 0;
                }
            }
        }
    }
}

bool check_cheese_exists() {
    for(int n=0; n < N; n++) {
        for(int m=0; m < M; m++) {
            if(my_map[n][m] == 1) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int n=0; n < N; n++) {
        for(int m=0; m < M; m++) {
            cin >> my_map[n][m];
        }
    }

    bool is_cheese_exists = true;
    int time = 0;

    while(is_cheese_exists) {
        bfs_to_set_outer_field();
        get_after_1_hour();
        is_cheese_exists = check_cheese_exists();
        time++;
    }
    
    cout << time << '\n';
}