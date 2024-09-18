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

    vector<int> D(N, 0);
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=0; i < N; i++) {
        cin >> D[i];
    }

    int ans = 0;
    int len = 1;
    int threshold = 10;
    while(true) {    
        for(int i=0; i <= N - len; i++) {
            int num = D[i];
            for(int j=1; j < len; j++) {
                num *= 10;
                num += D[i + j];
            }

            pq.push(num);
        }

        while(!pq.empty() && ans >= pq.top()) {
            if(ans == pq.top()) {
                ans++;
            }
            pq.pop();
        }

        if(ans != threshold) {
            break;
        }
        threshold *= 10;
        len++;
    }
    cout << ans << '\n';
}