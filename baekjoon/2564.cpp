#include <iostream>
#include <vector>
using namespace std;

int N, width, height;

int get_dist(const pair<int, int>& a, const pair<int, int>& b) {
    int dist = 0;

    // 같은 방향에 있는 경우
    if(a.first == b.first) {
        return abs(a.second - b.second);
    }

    if(a.first == 1) {
        if(b.first == 2) {
            dist = height + min(a.second + b.second, (width - a.second + width - b.second));
        } else if(b.first == 3) {
            dist = a.second + b.second;
        } else {
            dist = width - a.second + b.second;
        }
    } else if(a.first == 2) {
        if(b.first == 1) {
            dist = height + min(a.second + b.second, (width - a.second + width - b.second));
        } else if(b.first == 3) {
            dist = height - b.second + a.second;
        } else {
            dist = width - a.second + height - b.second;
        }
    } else if(a.first == 3) {
        if(b.first == 1) {
            dist = a.second + b.second;
        } else if(b.first == 2) {
            dist = height - a.second + b.second;
        } else {
            dist = width + min(a.second + b.second, (height - a.second + height - b.second));
        }
    } else {
        if(b.first == 1) {
            dist = width - b.second + a.second;
        } else if(b.first == 2) {
            dist = width - b.second + height - a.second;
        } else {
            dist = width + min(a.second + b.second, (height - a.second + height - b.second));
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int direction, dist;

    
    pair<int, int> start_pos;

    cin >> width >> height >> N;
    vector<pair<int, int>> stores(N, {0, 0});

    int ans = 0;
    for(int i=0; i < N; i++) {
        cin >> stores[i].first >> stores[i].second;
    }

    cin >> start_pos.first >> start_pos.second;

    for(int i=0; i < N; i++) {
        ans += get_dist(start_pos, stores[i]);
    }

    cout << ans << '\n';
}