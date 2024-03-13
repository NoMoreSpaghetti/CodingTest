#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;

int N, M;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

vvi room;
vector<pair<pii, int>> CCTVs;
vvi directions = {{}, {1}, {1, 3}, {0, 1}, {0, 1, 3}, {0, 1, 2, 3}};
vector<int> num_rotations = {0, 4, 2, 4, 4, 1};

// 비트로 해당 영역에서 감시 방향 표현
// 0000: 해당없음
// 0001: 0번째 방향{-1, 0}으로 감시 영역이 이어져 있음
// 0010: 1번째 방향{0, 1}으로 감시 영역이 이어져 있음
// ...

int dfs() {
    stack<pair<vvi, pii>> s;
    s.push({vvi(N, vector<int>(M, 0)), {0, 0}});

    int max_area_size = 0;

    while(!s.empty()) {
        vvi monitor_area = s.top().first;
        int cur_CCTV_idx = s.top().second.first;
        int area_size = s.top().second.second;
        s.pop();

        if(cur_CCTV_idx == CCTVs.size()) {
            max_area_size = max(max_area_size, area_size);
            continue;
        }
        pair<pii, int>& cur_CCTV = CCTVs[cur_CCTV_idx];

        for(int i=0; i < num_rotations[cur_CCTV.second]; i++) {
            vector<vector<int>> cur_monitor_area(monitor_area);
            int cur_area_size = area_size;
            for(auto& direction: directions[cur_CCTV.second]) {
                int next_y = cur_CCTV.first.first;
                int next_x = cur_CCTV.first.second;
                int next_direction = (direction + i) % 4;
                while(true) {
                    if(next_y >= 0 && next_y < N && next_x >= 0 && next_x < M) {
                        // 벽이 있으면 종료
                        if(room[next_y][next_x] == 6) {
                            break;
                        }
                        // 벽이 없고 해당 방향에 대한 검사가 진행되지 않았으면
                        if((cur_monitor_area[next_y][next_x] & (1 << next_direction)) == 0) {
                            if(cur_monitor_area[next_y][next_x] == 0) {
                                cur_area_size++;
                            }
                            cur_monitor_area[next_y][next_x] |= (1 << next_direction);
                        } else {
                            break;
                        }
                    } else {
                        break;
                    }
                    next_y += dy[next_direction];
                    next_x += dx[next_direction];
                }
            }
            s.push({cur_monitor_area, {cur_CCTV_idx + 1, cur_area_size}});
        }
    }

    return max_area_size;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    room = vvi(N, vector<int>(M, 0));
    int num_walls = 0;

    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            cin >> room[i][j];
            if(room[i][j] > 0 && room[i][j] < 6) {
                CCTVs.push_back({{i, j}, room[i][j]});
            } else if(room[i][j] == 6) {
                num_walls++;
            }
        }
    }

    int area_size = dfs();

    cout << N * M - area_size - num_walls << '\n';
}