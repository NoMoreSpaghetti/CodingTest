#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, H, T, inp;
    cin >> N >> H >> T;

    priority_queue<int> pq;

    for(int i=0; i < N; i++) {
        cin >> inp;
        pq.push(inp);
    }

    int i=0;
    for(i=0; i < T; i++) {
        if(pq.top() == 1 || pq.top() < H) {
            break;
        }
        inp = pq.top();
        pq.pop();
        pq.push(inp >> 1);
    }

    if(pq.top() < H) {
        cout << "YES" << '\n';
        cout << i << '\n';
    } else {
        cout << "NO" << '\n';
        cout << pq.top() << '\n';
    }
}