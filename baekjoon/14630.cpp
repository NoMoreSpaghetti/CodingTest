#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;

int N, cur, target;
string part_nums[1000];
long long dist[1000];

long long get_cost(string s1, string s2) {
    long long cost = 0;
    for(int i=0; i < s1.length(); i++) {
        cost += (s1[i] - s2[i]) * (s1[i] - s2[i]);
    }
    return cost;
}

long long dijkstra() {
    priority_queue<pair<long long, int>> pq;
    pq.push({0, cur - 1});
    fill(&dist[0], &dist[999], LLONG_MAX);
    while(!pq.empty()) {
        long long here_cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        for(int i=0; i < N; i++) {
            long long there_cost = here_cost + get_cost(part_nums[i], part_nums[here]);
            if(dist[i] > there_cost) {
                dist[i] = there_cost;
                pq.push({-there_cost, i});
            }
        }
    }

    return dist[target - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i=0; i < N; i++) {
        cin >> part_nums[i];
    }

    cin >> cur >> target;

    cout << dijkstra() << '\n';
}