#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int cur_ticket, inp;
    priority_queue<int> pq;

    cin >> cur_ticket;
    for(int i=1; i < N; i++) {
        cin >> inp;
        pq.push(inp);
    }

    int count = 0;
    if(N >= 2) {
        while(pq.top() >= cur_ticket) {
            int top_ticket = pq.top();
            pq.pop();
            cur_ticket++;
            top_ticket--;
            pq.push(top_ticket);
            count++;
        }
    }

    cout << count << '\n';
}