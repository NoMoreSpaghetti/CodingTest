#include <iostream>
#include <queue>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, inp;
    cin >> T;
    for(int t=1; t <= T; t++) {
        priority_queue<int> pq;
        set<int> s;
        for(int i=0; i < 3; i++) {
            cin >> inp;
            pq.push(inp);
            s.insert(inp);
        }

        int valid_check = pq.top();
        pq.pop();

        valid_check -= pq.top();
        pq.pop();

        valid_check -= pq.top();
        pq.pop();

        cout << "Case #" << t << ": ";
        if(valid_check >= 0) {
            cout << "invalid!" << '\n';
        } else if(s.size() == 3) {
            cout << "scalene" << '\n';
        } else if(s.size() == 2) {
            cout << "isosceles" << '\n';
        } else {
            cout << "equilateral" << '\n';
        }
    }
}