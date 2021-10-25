#include <iostream>
#include <vector>
#include <climits>
#include <string.h>
using namespace std;

bool BF_algorithm(vector<pair<int, int>> v[], int N, int dist_ary[]) {
    fill_n(dist_ary, N + 1, 0);

    bool updated;

    for(int n=0; n < N - 1; n++) {
        updated = false;
        for(int here=1; here <= N; here++) {
            for(int j=0; j < v[here].size(); j++) {
                int there = v[here][j].first;
                int cost = v[here][j].second;
                if(dist_ary[there] > dist_ary[here] + cost) {
                    dist_ary[there] = dist_ary[here] + cost;
                    updated = true;
                }
            }
        }
        if(!updated) {
            break;
        }
    }

    for(int here = 1; here <= N; here++) {
        for(int j=0; j < v[here].size(); j++) {
            int there = v[here][j].first;
            int cost = v[here][j].second;
            if(dist_ary[there] > dist_ary[here] + cost) {
                return false;
            }
        }
    }

    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC, N, M, W, S, E, T;

    cin >> TC;
    for(int tc=0; tc < TC; tc++) {
        int dist_ary[501];
        vector<pair<int, int>> v[501];
        // vector<pair<int, int>> w[501];

        cin >> N >> M >> W;
        for(int i=0; i < M; i++) {
            cin >> S >> E >> T;
            v[S].push_back(make_pair(E, T));
            v[E].push_back(make_pair(S, T));
        }
        for(int i=0; i < W; i++) {
            cin >> S >> E >> T;
            v[S].push_back(make_pair(E, -T));
        }

        bool no_minus = BF_algorithm(v, N, dist_ary);
        string s = "YES";
        if(no_minus) {
            s = "NO";
        }
        cout << s << '\n';
    }
}