#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, inp, idx;
    cin >> N;

    priority_queue<int, vector<int>, less<int>> pq_low;
    priority_queue<int, vector<int>, greater<int>> pq_high;
    vector<int> vec = vector<int>(N, 0);

    for(int i=0; i < N; i++) {
        cin >> inp;
        if(pq_low.empty()) {
            pq_low.push(inp);
        } else {
            if(inp <= pq_low.top()) {
                pq_low.push(inp);
            } else {
                pq_high.push(inp);
            }
        }

        if(pq_low.size() < pq_high.size()) {
            pq_low.push(pq_high.top());
            pq_high.pop();
        } else if(pq_low.size() > pq_high.size() + 1) {
            pq_high.push(pq_low.top());
            pq_low.pop();
        }

        // cout << "low size" << pq_low.size() << " high size" << pq_high.size() << '\n';

        cout << pq_low.top() << '\n';
    }
}