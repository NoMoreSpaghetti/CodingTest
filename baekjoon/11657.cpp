#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int N, M;
vector<long long> dist;
vector<tuple<int, int, long long>> edges;

bool bellman_ford(int start) {
    int cur, next;
    long long cost;
    dist[start] = 0;

    // N - 1 번 반복
    for(int i=0; i < N -1; i++) {
        for(auto& element : edges) {
            cur = get<0>(element);
            next = get<1>(element);
            cost = get<2>(element);

            // next를 거치는 거리가 더 짧으면 갱신
            if(dist[cur] != INT64_MAX && dist[next] > dist[cur] + cost) {
                dist[next] = dist[cur] + cost;
            }
        }
    }

    // N번째 반복
    for(auto& element : edges) {
        cur = get<0>(element);
        next = get<1>(element);
        cost = get<2>(element);

        // 갱신이 발생하면 음의 가중치 존재
        if(dist[cur] != INT64_MAX && dist[next] > dist[cur] + cost) {
            return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B;
    long long C;
    cin >> N >> M;

    edges = vector<tuple<int, int, long long>>(M, tuple<int, int, long long>());
    dist = vector<long long>(N + 1, INT64_MAX);

    for(int i=0; i < M; i++) {
        cin >> A >> B >> C;
        edges[i] = make_tuple(A, B, C);
    }

    if(bellman_ford(1)) {
        for(int i=2; i < dist.size(); i++) {
            if(dist[i] == INT64_MAX) {
                cout << -1 << '\n';
            } else {
                cout << dist[i] << '\n';
            }
        }
    } else {
        cout << -1 << '\n';
    }
}