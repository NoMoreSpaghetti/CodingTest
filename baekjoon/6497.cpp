#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n;

vector<pair<int, pair<int, int>>> lines;
vector<int> roots;
vector<int> ranks;

int Find(int a) {
    if(roots[a] == a) return a;

    return roots[a] = Find(roots[a]);
}

void Merge(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a == b) return;
    if(ranks[a] > ranks[b]) roots[b] = a;
    else {
        roots[a] = b;
        if(ranks[a] == ranks[b]) {
            ranks[b]++;
        }
    }
}

int Kruskal() {
    int ans = 0;
    for(auto& line : lines) {
        int cost = line.first;
        int a = line.second.first;
        int b = line.second.second;

        if(Find(a) != Find(b)) {
            Merge(a, b);
        } else {
            ans += cost;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;

    while(m != 0 && n != 0) {
        lines.clear();
        roots = vector<int>(m, 0);
        ranks = vector<int>(m, 0);

        for(int i=0; i < m; i++) {
            roots[i] = i;
        }

        int x, y, z;
        for(int i=0; i < n; i++) {
            cin >> x >> y >> z;

            lines.push_back({z, {x, y}});
        }

        sort(lines.begin(), lines.end());

        cout << Kruskal() << '\n';

        cin >> m >> n;
    }
}