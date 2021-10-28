#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;

int BUS_COST_MAX = 100001;
int n, m;
long long costs[1001];
int visits[1001][2];
int v[1001][1001];

void dijkstra(int start) {    
    fill_n(costs, 1001, INT_MAX);
    priority_queue<pair<int, long long>> pq;
    pq.push(make_pair(start, 0));
    costs[start] = 0;
    visits[start][0] = -1;
    visits[start][1] = 1;

    while(!pq.empty()) {
        int here = pq.top().first;
        long long here_cost = -pq.top().second;
        pq.pop();

        for(int there=1; there < 1001; there++) {
            if(v[here][there] != BUS_COST_MAX) {
                long long there_cost = v[here][there] + here_cost;

                if(costs[there] > there_cost) {
                    costs[there] = there_cost;
                    visits[there][0] = here;
                    visits[there][1] = visits[here][1] + 1;
                    pq.push(make_pair(there, -there_cost));
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int start, dest, cost;
    cin >> n >> m;

    fill(&v[0][0], &v[1000][1001], BUS_COST_MAX);

    for(int i=0; i < m; i++) {
        cin >> start >> dest >> cost;
        if(cost < v[start][dest]) {
            v[start][dest] = cost;
        }
    }
    cin >> start >> dest;

    dijkstra(start);

    cout << costs[dest] << '\n';
    cout << visits[dest][1] << '\n';
    int temp = dest;
    stack<int> s;
    s.push(temp);
    while(true) {
        temp = visits[temp][0];
        if(temp == -1) {
            break;
        }
        s.push(temp);
    }
    while(!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
}