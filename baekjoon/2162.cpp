#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int, int>
using namespace std;

int N;
vector<int> roots;
vector<int> ranks;
vector<pair<pii, pii>> lines;

int ccw(const pii& p1, const pii& p2, const pii& p3) {
    int s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    s -= p2.first * p1.second + p3.first * p2.second + p1.first * p3.second;

    if(s > 0) {
        return 1;
    } else if(s == 0) {
        return 0;
    } else {
        return -1;
    }
}

bool is_intersect(const pair<pii, pii>& l1, const pair<pii, pii>& l2) {
    pii p1 = l1.first;
    pii p2 = l1.second;
    pii p3 = l2.first;
    pii p4 = l2.second;

    int l1_s = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int l2_s = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    if(l1_s == 0 && l2_s == 0) {
        if(p1 > p2) swap(p1, p2);
        if(p3 > p4) swap(p3, p4);
        return p2 >= p3 && p4 >= p1;
    }
    return l1_s <= 0 && l2_s <= 0;
}

int my_find(int n) {
    if(roots[n] == n) {
        return n;
    }
    return roots[n] = my_find(roots[n]);
}

void my_union(int a, int b) {
    a = my_find(a);
    b = my_find(b);

    if(a == b) {
        return;
    } else {
        if(ranks[a] > ranks[b]) {
            swap(a, b);
        }
        roots[a] = b;
        if(ranks[a] == ranks[b]) {
            ranks[b]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    roots = vector<int>(N, 0);
    ranks = vector<int>(N, 0);
    int x1, y1, x2, y2;

    for(int i=0; i < N; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        lines.push_back({{x1, y1}, {x2, y2}});
        roots[i] = i;
    }
    
    for(int i=0; i < N - 1; i++) {
        for(int j=i + 1; j < N; j++) {
            if(is_intersect(lines[i], lines[j])) {
                my_union(i, j);
            }
        }
    }

    vector<int> sizes(N, 0);
    for(auto& element: roots) {
        sizes[my_find(element)]++;
    }

    sort(sizes.begin(), sizes.end(), greater<>());

    int num_groups = 0;
    for(; num_groups < N; num_groups++) {
        if(sizes[num_groups] == 0) {
            break;
        }
    }

    cout << num_groups << '\n' << sizes[0] << '\n';
}