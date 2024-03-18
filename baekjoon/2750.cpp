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
    priority_queue<int, vector<int>, greater<int>> pq;
    int inp;

    for(int i=0; i < N; i++) {
        cin >> inp;
        pq.push(inp);
    }

    while(!pq.empty()) {
        cout << pq.top() << '\n';
        pq.pop();
    }
}