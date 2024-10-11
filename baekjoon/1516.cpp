#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<vector<int>> next_buildings; 
vector<int> in_degrees;
vector<int> build_times;
vector<int> ans;

void TopologySort() {
    queue<int> q;

    for(int i=1; i <= N; i++) {
        if(in_degrees[i] == 0) {
            ans[i] = build_times[i];
            q.push(i);
        }
    }

    for(int i=1; i <= N; i++) {
        // 사이클 발생 확인
        if(q.empty()) {
            return;
        }

        int cur = q.front();
        q.pop();

        for(auto& next_building: next_buildings[cur]) {
            ans[next_building] = max(ans[next_building], ans[cur]);
            if(--in_degrees[next_building] == 0) {
                ans[next_building] += build_times[next_building];
                q.push(next_building);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    next_buildings = vector<vector<int>>(N + 1, vector<int>());
    in_degrees = vector<int>(N + 1, 0);
    build_times = vector<int>(N + 1, 0);
    ans = vector<int>(N + 1, 0);

    int build_time, prev_building;
    for(int i=1; i <= N; i++) {
        cin >> build_time;
        build_times[i] = build_time;

        cin >> prev_building;
        while(prev_building != -1) {
            next_buildings[prev_building].push_back(i);
            in_degrees[i]++;
            cin >> prev_building;
        }
    }

    TopologySort();
    
    for(int i=1; i <= N; i++) {
        cout << ans[i] << '\n';
    }
}