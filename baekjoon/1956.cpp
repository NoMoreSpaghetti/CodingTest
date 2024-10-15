#include <iostream>
#include <vector>
#define MAX_VAL (10000000)
using namespace std;

int V, E;
vector<vector<int>> graph;

void Floyd() {
    for(int k=1; k <= V; k++) {
        for(int i=1; i <= V; i++) {
            for(int j=1; j <= V; j++) {
                if(graph[i][k] != MAX_VAL && graph[k][j] != MAX_VAL) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
}

int GetMinimunCycleLen() {
    int return_val = INT32_MAX;
    for(int i=1; i <= V; i++) {
        for(int j=1; j <= V; j++) {
            if(graph[i][j] != MAX_VAL && graph[j][i] != MAX_VAL) {
                return_val = min(return_val, graph[i][j] + graph[j][i]);
            }
        }
    }

    if(return_val == INT32_MAX) {
        return_val = -1;
    }

    return return_val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    graph = vector<vector<int>>(V + 1, vector<int>(V + 1, MAX_VAL));

    int a, b, c;
    for(int i=0; i < E; i++) {
        cin >> a >> b >> c;
        graph[a][b] = c;
    }

    Floyd();
    cout << GetMinimunCycleLen() << '\n';
}