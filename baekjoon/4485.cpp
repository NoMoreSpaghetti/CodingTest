#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<vector<int>> cave;
vector<vector<int>> lost_rupees;
vector<vector<bool>> visited;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

struct cmp {
    bool operator()(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
        return a.second > b.second;
    }
};

void get_num_lost_rupees(pair<int, int> start) {
    int next_y, next_x;
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, cmp> pq;

    pair<int, int> cur_pos = start;
    int lost_rupee = 0;

    pq.push({start, cave[start.first][start.second]});
    visited[start.first][start.second] = true;
    lost_rupees[start.first][start.second] = cave[start.first][start.second];
    
    while(true) {
        cur_pos = pq.top().first;
        pq.pop();
        lost_rupee = lost_rupees[cur_pos.first][cur_pos.second];

        // if(cur_pos.first == N - 1 && cur_pos.second == N - 1) {
        //     break;
        // }

        for(int i=0; i < 4; i++) {
            next_y = cur_pos.first + dy[i];
            next_x = cur_pos.second + dx[i];
            if(next_y < 0 || next_y >= N || next_x < 0 || next_x >= N) {
                continue;
            }

            if(!visited[next_y][next_x]) {
                int next_lost_rupee = cave[next_y][next_x] + lost_rupee;
                pq.push({{next_y, next_x}, next_lost_rupee});
                visited[next_y][next_x] = true;
                lost_rupees[next_y][next_x] = next_lost_rupee;
                if(next_y == N - 1 && next_x == N - 1) {
                    return;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int problem_idx = 1, inp;
    cin >> N;
    while(N != 0) {
        cave = vector<vector<int>>(N, vector<int>(N, 0));
        lost_rupees = vector<vector<int>>(N, vector<int>(N, 0));
        visited = vector<vector<bool>>(N, vector<bool>(N, false));

        for(int i=0; i < N; i++) {
            for(int j=0; j < N; j++) {
                cin >> inp;
                cave[i][j] = inp;
            }
        }

        get_num_lost_rupees({0, 0});
        cout << "Problem " << problem_idx++ << ": " << lost_rupees[N - 1][N - 1] << '\n';

        cin >> N;
    }
}