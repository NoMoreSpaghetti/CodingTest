#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, inp;
    vector<pair<int, int>> ones;
    cin >> N >> M;
    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            cin >> inp;
            if(inp == 1) {
                ones.push_back({i, j});
            }
        }
    }

    cout << abs(ones[0].first - ones[1].first) + abs(ones[0].second - ones[1].second) << '\n';
}