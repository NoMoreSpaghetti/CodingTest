#include <iostream>
#include <vector>
using namespace std;

int N, M, P;

int dfs(vector<vector<int>>& channels, int start_num) {
    int num_changed = -1;
    vector<bool> visited(M + 1, false);
    vector<int> s;
    visited[start_num] = true;
    s.push_back(start_num);
    while(!s.empty()) {
        int cur = s.front();
        s.pop_back();
        num_changed++;
        if(!channels[cur].empty()) {
            int next_channel = channels[cur].front();
            if(visited[next_channel]) {
                return -1;
            } else {
                visited[next_channel] = true;
                s.push_back(next_channel);
            }
        }
    }
    return num_changed;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> P;

    vector<vector<int>> channels(M + 1, vector<int>());

    int inp1, inp2;
    for(int i=0; i < N; i++) {
        cin >> inp1 >> inp2;
        channels[inp2].push_back(inp1);
    }

    cout << dfs(channels, P) << '\n';
}