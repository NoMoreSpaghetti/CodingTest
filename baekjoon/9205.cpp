#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;

const int max_dist = 20 * 50;

int calc_dist(const pair<int, int>& p1, const pair<int, int>& p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

bool bfs(const int& n, const vector<pair<int, int>>& conv_points, const pair<int, int>& house, const pair<int, int>& fes) {
    queue<pair<int, int>> q;
    vector<bool> visited(n, false);;
    q.push(house);

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        // fes에 도착 가능하면 종료
        if(calc_dist(cur, fes) <= max_dist) {
            return true;
        }

        for(int i=0; i < n; i++) {
            if(visited[i] == false && calc_dist(cur, conv_points[i]) <= max_dist) {
                visited[i] = true;
                q.push(conv_points[i]);
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, x, y;
    
    cin >> t;
    while(t--) {
        int house_y, house_x, fes_y, fes_x;
        vector<pair<int, int>> convenience_store_points;
        
        cin >> n;
        cin >> house_y >> house_x;
        for(int i=0; i < n; i++) {
            cin >> y >> x;
            convenience_store_points.push_back({y, x});
        }
        cin >> fes_y >> fes_x;

        if(bfs(n, convenience_store_points, {house_y, house_x}, {fes_y, fes_x})) {
            cout << "happy" << '\n';
        } else {
            cout << "sad" << '\n';
        }
    }


}