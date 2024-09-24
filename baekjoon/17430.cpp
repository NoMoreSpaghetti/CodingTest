#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, x, y;
    cin >> T;

    while(T--) {
        cin >> N;
        set<int> xs;
        set<int> ys;
        map<int, vector<int>> m;
        
        for(int i=0; i < N; i++) {
            cin >> x >> y;
            xs.insert(x);
            ys.insert(y);
            m[x].push_back(y);
        }

        for(auto& kv_pair: m) {
            sort(kv_pair.second.begin(), kv_pair.second.end());
        }

        bool balanced = true;

        auto iter = m.begin();
        auto iter2 = m.begin();
        iter2++;

        while(iter2 != m.end()) {
            if(iter->second != iter2->second) {
                balanced = false;
            }
            iter2++;
        }

        if(balanced) {
            cout << "BALANCED" << '\n';
        } else {
            cout << "NOT BALANCED" << '\n';
        }
    }
}