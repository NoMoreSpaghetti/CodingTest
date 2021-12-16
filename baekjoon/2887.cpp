#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <math.h>
#define INF (90000000000.0)
using namespace std;

int N;
vector<pair<int, int>> planets[3];
int roots[100000];
int ranks[100000] = {0};

int my_find(int x) {
    if(roots[x] == x) {
        return x;
    } else {
        return roots[x] = my_find(roots[x]);
    }
}

void my_union(int x, int y) {
    x = my_find(x);
    y = my_find(y);

    if(x == y) {
        return;
    } else {
        if(ranks[x] < ranks[y]) {
            roots[x] = y;
        } else {
            roots[y] = x;
            if(ranks[x] == ranks[y]) {
                ranks[x]++;
            }
        }
    }
}

long long kruskal() {
    long long ans = 0;
    vector<tuple<int, int, int>> weights;
    
    for(int i=0; i < N - 1; i++) {
        int x_weight = abs(planets[0][i].first - planets[0][i + 1].first);
        int y_weight = abs(planets[1][i].first - planets[1][i + 1].first);
        int z_weight = abs(planets[2][i].first - planets[2][i + 1].first);
        weights.push_back(make_tuple(x_weight, planets[0][i].second, planets[0][i + 1].second));
        weights.push_back(make_tuple(y_weight, planets[1][i].second, planets[1][i + 1].second));
        weights.push_back(make_tuple(z_weight, planets[2][i].second, planets[2][i + 1].second));
    }

    sort(weights.begin(), weights.end());

    for(int i=0; i < weights.size(); i++) {
        int weight = get<0>(weights[i]);
        int p1 = get<1>(weights[i]);
        int p2 = get<2>(weights[i]);

        if(my_find(p1) != my_find(p2)) {
            my_union(p1, p2);
            ans += weight;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y, z;
    cin >> N;
    for(int i=0; i < N; i++) {
        cin >> x >> y >> z;
        planets[0].push_back({x, i});
        planets[1].push_back({y, i});
        planets[2].push_back({z, i});
        roots[i] = i;
    }

    sort(planets[0].begin(), planets[0].end());
    sort(planets[1].begin(), planets[1].end());
    sort(planets[2].begin(), planets[2].end());

    cout << kruskal() << '\n';
}