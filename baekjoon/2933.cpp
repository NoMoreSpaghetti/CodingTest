#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int R, C, N;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};
vector<vector<int>> cave;

bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
    if(p1.first == p2.first) {
        return p1.second < p2.second;
    }
    return p1.first < p2.first;
}

bool fall_down(int cur_y, int cur_x) {
    // bfs
    stack<pair<int, int>> s;
    stack<pair<int, int>> s2;
    vector<vector<int>> visited(R, vector<int>(C, false));

    // 각 y축이 떨어질 수 있는 높이
    vector<pair<int, int>> y_intervals(C, pair<int, int>(R, C));

    s.push({cur_y, cur_x});
    s2.push({cur_y, cur_x});
    visited[cur_y][cur_x] = true;
    int min_interval = cur_y;

    while(!s.empty()) {
        cur_y = s.top().first;
        cur_x = s.top().second;
        s.pop();

        int next_y = cur_y - 1;
        int next_x = cur_x;
        int interval = cur_y;

        if(cur_y == 0) {
            min_interval = 0;
            break;
        }

        // 클러스터 각 열의 맨 아래가 바닥이나 미네랄에 닿는 것만 고려함 
        if(cave[next_y][next_x] == 0) {
        // if(cur_y > 0 && cur_y < y_intervals[cur_x].first && cave[next_y][next_x] == 0) {
            interval = 1;
            next_y--;
            while(next_y >= 0) {
                if(cave[next_y][next_x] > 0) {
                    break;
                }
                interval++;
                next_y--;
            }
            y_intervals[cur_x] = min(y_intervals[cur_x], {cur_y, interval}, compare);
        }

        for(int i=0; i < 4; i++) {
            next_y = cur_y + dy[i];
            next_x = cur_x + dx[i];
            if(next_y < 0 || next_y >= R || next_x < 0 || next_x >= C) {
                continue;
            }
            if(cave[next_y][next_x] > 0) {
                if(visited[next_y][next_x]) {
                    continue;
                }
                visited[next_y][next_x] = true;
                s.push({next_y, next_x});
                s2.push({next_y, next_x});
            }
        }
    }

    if(min_interval > 0) {
        for(int i=0; i < C; i++) {
            if(y_intervals[i].second < min_interval) {
                min_interval = y_intervals[i].second;
            }
        }

        while(!s2.empty()) {
            cur_y = s2.top().first;
            cur_x = s2.top().second;
            s2.pop();

            cave[cur_y][cur_x]--;
            cave[cur_y - min_interval][cur_x]++;
        }
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    cave = vector<vector<int>>(R, vector<int>(C, 0));
    char inp;

    for(int i=R - 1; i >= 0; i--) {
        for(int j=0; j < C; j++) {
            cin >> inp;
            if(inp == 'x') {
                cave[i][j] = 1;
            }
        }
    }

    cin >> N;
    int height;
    bool is_left = true;

    for(int i=0; i < N; i++) {
        cin >> height;
        height--;
        int hit_point_y = -1;
        int hit_point_x = -1;

        if(is_left) {
            for(int i=0; i < C; i++) {
                if(cave[height][i] > 0) {
                    hit_point_y = height;
                    hit_point_x = i;
                    break;
                }
            }
        } else {
            for(int i=C - 1; i >= 0; i--) {
                if(cave[height][i] > 0) {
                    hit_point_y = height;
                    hit_point_x = i;
                    break;
                }
            }
        }


        // 막대가 맞았으면
        if(hit_point_y != -1) {
            cave[hit_point_y][hit_point_x]--;
            stack<pair<int, int>> s;
            
            // 연결된 블럭 찾기
            for(int i=0; i < 4; i++) {
                int next_y = hit_point_y + dy[i];
                int next_x = hit_point_x + dx[i];
                if(next_y < 0 || next_y >= R || next_x < 0 || next_x >= C) {
                    continue;
                }

                if(cave[next_y][next_x] > 0) {
                    s.push({next_y, next_x});
                    
                }
            }

            while(!s.empty()) {
                int next_y = s.top().first;
                int next_x = s.top().second;
                s.pop();
                if(fall_down(next_y, next_x)) {
                    break;
                }
            }
        }

        is_left = !is_left;
    }

    for(int i=R - 1; i >= 0; i--) {
        for(int j=0; j < C; j++) {
            if(cave[i][j] < 1) {
                cout << '.';
            } else {
                cout << 'x';
            }
        }
        cout << '\n';
    }
}
