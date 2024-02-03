#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int s, t;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i=0; i < N; i++) {
        cin >> s >> t;
        pq.push({s, t});
    }

    priority_queue<int, vector<int>, greater<int>> vec;
    vec.push(pq.top().second);
    pq.pop();

    while(!pq.empty()) {
        pair<int, int> s_t = pq.top();
        pq.pop();

        if(vec.top() <= s_t.first) {
            vec.pop();
        }
        vec.push(s_t.second);
    }
    cout << vec.size() << '\n';
}