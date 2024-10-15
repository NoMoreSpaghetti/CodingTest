#include <iostream>
#include <vector>
#define MAX_VAL (100000)
using namespace std;

int N, M;
vector<vector<int>> graph;

void Floyd() {
    for(int k=1; k <= N; k++) {
        for(int i=1; i <= N; i++) {
            for(int j=1; j <= N; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    graph = vector<vector<int>>(N + 1, vector<int>(N + 1, MAX_VAL));
    for(int i=1; i <= N; i++) {
        graph[i][i] = 0;
    }

    int a, b;
    for(int i=0; i < M; i++) {
        cin >> a >> b;

        graph[a][b] = 1;
    }

    Floyd();

    int ans = 0;
    for(int i=1; i <= N; i++) {
        bool is_ans = true;
        for(int j=1; j <= N; j++) {
            if(graph[i][j] == MAX_VAL && graph[j][i] == MAX_VAL) {
                is_ans = false;
                break;
            }
        }

        if(is_ans) ans++;
    }

    cout << ans << '\n';
}