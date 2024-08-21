#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

vector<bool> visited;

double get_dist(pair<int, int>& a, pair<int, int>& b) {
    double x = a.first - b.first;
    double y = a.second - b.second;
    return sqrt(x * x + y * y);
}

double dfs(vector<pair<int, int>>& vec, pair<int, int> cur, int cnt, double dist) {
    if(cnt == 3) {
        return dist;
    }

    double min_dist = __DBL_MAX__;

    for(int i=0; i < 3; i++) {
        if(visited[i] == false) {
            visited[i] = true;
            double new_dist = dfs(vec, vec[i], cnt + 1, dist + get_dist(cur, vec[i]));
            visited[i] = false;
            min_dist = min(min_dist, new_dist);
        }
    }

    return min_dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y;
    vector<pair<int, int>> vec(3, {0, 0});
    visited = vector<bool>(3, false);
    cin >> x >> y;

    for(int i=0; i < 3; i++) {
        cin >> vec[i].first >> vec[i].second;
    }

    cout << trunc(dfs(vec, {x, y}, 0, 0)) << '\n';
}