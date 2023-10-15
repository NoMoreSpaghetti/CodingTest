#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> candies;
vector<int> group_size;
vector<int> parents;
vector<int> ranks;

int find_parent(int x) {
    if(parents[x] == x) {
        return x;
    } else {
        return parents[x] = find_parent(parents[x]);
    }
}

void union_parent(int x, int y) {
    x = find_parent(x);
    y = find_parent(y);

    if(x == y) {
        return;
    } else {
        if(ranks[x] > ranks[y]) {
            parents[y] = x;
            candies[x] += candies[y];
            candies[y] = 0;
            group_size[x] += group_size[y];
            group_size[y] = 0;
        } else {
            parents[x] = y;
            if(ranks[x] == ranks[y]) {
                ranks[y]++;
            }
            candies[y] += candies[x];
            candies[x] = 0;
            group_size[y] += group_size[x];
            group_size[x] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K, a, b;
    cin >> N >> M >> K;

    candies = vector<int>(N + 1, 0);
    group_size = vector<int>(N + 1, 1);
    parents = vector<int>(N + 1, -1);
    ranks = vector<int>(N + 1, 1);

    for(int i=1; i <= N; i++) {
        cin >> candies[i];
        parents[i] = i;
    }

    for(int i=0; i < M; i++) {
        cin >> a >> b;
        union_parent(a, b);
    }

    // 모든 그룹의 루트 찾아서 저장
    vector<int> roots;
    for(int i=1; i <= N; i++) {
        if(candies[i] != 0) {
            roots.push_back(i);
        }
    }

    // 사람 수에 따른 최대 개수
    vector<int> dp(K, 0);
    for(int i=0; i < roots.size(); i++) {
        int idx = roots[i];

        // 중복 계산될 우려가 있기에
        // K-1부터 내림차순으로 계산
        for(int j=K-1; j >= group_size[idx]; j--) {
            dp[j] = max(dp[j], dp[j - group_size[idx]] + candies[idx]);
        }
    }

    cout << dp[K - 1] << '\n';
}