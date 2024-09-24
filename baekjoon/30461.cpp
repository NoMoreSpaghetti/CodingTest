#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, Q, W, P;
    cin >> N >> M >> Q;

    vector<vector<int>> area(N, vector<int>(M, 0));

    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            cin >> area[i][j];
        }
    }

    vector<vector<int>> cumulative_area(area);

    if(N >= 2) {
        cumulative_area[1][0] += area[0][0];
        for(int j=1; j < M; j++) {
            cumulative_area[1][j] += area[0][j] + area[0][j - 1];
        }
    }
    
    for(int i=2; i < N; i++) {
        cumulative_area[i][0] += cumulative_area[i - 1][0];
        for(int j=1; j < M; j++) {
            cumulative_area[i][j] += cumulative_area[i - 1][j] + cumulative_area[i - 1][j - 1] - cumulative_area[i - 2][j - 1];
        }
    }

    for(int i=0; i < Q; i++) {
        cin >> W >> P;
        W--;
        P--;

        cout << cumulative_area[W][P] << '\n';
    }
}