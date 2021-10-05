#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
using namespace std;


int N, M;
int board[50][50];
int chicken[13][2];
int house[100][2];
int chicken_idx = 0;
int house_idx = 0;

bool visited_chicken[13];

int answer = INT_MAX;

int calc_dist() {
    int sum_of_distance = 0;
    for(int h=0; h < house_idx; h++) {
        int min_dist = INT_MAX;
        for(int c=0; c < 13; c++) {
            if(visited_chicken[c] == false) {
                continue;
            }

            int dist = abs(chicken[c][0] - house[h][0]) + abs(chicken[c][1] - house[h][1]);
            min_dist = min(dist, min_dist);
        }
        sum_of_distance += min_dist;
    }
    return sum_of_distance;
}

void dfs(int idx, int cnt) {
    if(cnt == M) {
        answer = min(answer, calc_dist());
        return;
    }

    for(int i=idx; i < chicken_idx; i++) {
        if(!visited_chicken[i]) {
            visited_chicken[i] = true;
            dfs(i + 1, cnt + 1);
            visited_chicken[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(board, 0, sizeof(board));
    memset(visited_chicken, false, sizeof(visited_chicken));

    cin >> N >> M;

    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            cin >> board[i][j];
            if(board[i][j] == 2) {
                chicken[chicken_idx][0] = i;
                chicken[chicken_idx][1] = j;
                chicken_idx++;
            } else if (board[i][j] == 1) {
                house[house_idx][0] = i;
                house[house_idx][1] = j;
                house_idx++;
            }
        }
    }

    dfs(0, 0);
    cout << answer << '\n';
}
