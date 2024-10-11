#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;

vector<int> in_degrees;
vector<vector<int>> next_ids;

void TopologySort() {
    queue<int> q;
    vector<int> dists(N + 1, 1);

    for(int i=1; i <= N; i++) {
        if(in_degrees[i] == 0) {
            q.push(i);
            dists[i] = 1;
        }
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(auto& next_id: next_ids[cur]) {
            dists[next_id] = max(dists[next_id], dists[cur]);
            if(--in_degrees[next_id] == 0) {
                q.push(next_id);
                dists[next_id] += 1;
            }
        }
    }

    for(int i=1; i <= N; i++) {
        cout << dists[i] << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    next_ids = vector<vector<int>>(N + 1, vector<int>());
    in_degrees = vector<int>(N + 1, 0);

    int A, B;
    for(int i=0; i < M; i++) {
        cin >> A >> B;
        in_degrees[B]++;
        next_ids[A].push_back(B);
    }

    TopologySort();
}