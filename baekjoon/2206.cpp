#include <iostream>
#include <queue>
#include <tuple>
#include <string.h>
using namespace std;

int N, M;
int my_map[1000][1000];
bool visited[2][1000][1000];
int dist_MAX = 2000;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs() {
    memset(visited, false, sizeof(visited));
    visited[1][0][0] = true;
    int min_dist = dist_MAX;
    queue<tuple<int, int, int, int>> q;
    q.push(make_tuple(0, 0, 0, 1));
    

    while(!q.empty()) {
        tuple<int, int, int, int> here = q.front();
        q.pop();

        // 도착하면 거리 반환
        if(get<0>(here) == N-1 && get<1>(here) == M-1) {
            min_dist = get<2>(here) + 1;
            break;
        }

        for(int i=0; i < 4; i++) {
            int new_y = get<0>(here) + dy[i];
            int new_x = get<1>(here) + dx[i];
            // 범위 벗어나면 continue;
            if(new_y >= N || new_x >= M || new_y < 0 || new_x < 0) {
                continue;
            }
            // 벽이 없으면
            if(my_map[new_y][new_x] == 0) {
                tuple<int, int, int, int> there = make_tuple(new_y, new_x, get<2>(here) + 1, get<3>(here));
                if(get<3>(here) == 1) {
                    if(visited[1][new_y][new_x] == false) {
                        visited[1][new_y][new_x] = true;
                        q.push(there);
                    }
                } else {
                    if(visited[0][new_y][new_x] == false) {
                        visited[0][new_y][new_x] = true;
                        q.push(there);
                    }
                }
            // 벽이 있으면
            } else {
                // 부술 기회가 있으면
                if(get<3>(here) == 1 && visited[0][new_y][new_x] == false) {
                    tuple<int, int, int, int> there = make_tuple(new_y, new_x, get<2>(here) + 1, get<3>(here) - 1);
                    q.push(there);
                    visited[0][new_y][new_x] = true;
                }
            }
        }
    }
    return min_dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    string s;

    for(int n=0; n < N; n++) {
        cin >> s;
        for(int m=0; m < M; m++) {
            my_map[n][m] = s[m] - '0';
        }
    }

    int min_dist = bfs();
    if(min_dist == dist_MAX) {
        cout << -1 << '\n';
    } else {
        cout << min_dist << '\n';
    }
}