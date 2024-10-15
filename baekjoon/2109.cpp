#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
priority_queue<pair<int, int>> pq;
vector<int> p_vec(10001, 0);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int d, p;
    int ans = 0;

    cin >> n;

    for(int i=0; i < n; i++) {
        cin >> p >> d;
        pq.push({p, -d});
    }

    while(!pq.empty()) {
        int cur_p = pq.top().first;
        int cur_d = -pq.top().second;
        
        pq.pop();

        int i = cur_d;
        while(i > 0 && p_vec[i] != 0) {
            i--;
        }
        if(i > 0) {
            p_vec[i] = cur_p;
        }
    }

    for(int i=1; i <= 10000; i++) {
        ans += p_vec[i];
    }

    cout << ans << '\n';
}