#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, n, l, w;
    cin >> T;

    while(T--) {
        cin >> n;
        
        int ans = 0;
        vector<pair<int, int>> vec;
        for(int i=0; i < n; i++) {
            cin >> l >> w;
            vec.push_back({l, w});
        }

        sort(vec.begin(), vec.end());

        while(!vec.empty()) {
            int min_weight = -1;
            for(auto wood_stick=vec.begin(); wood_stick != vec.end();) {
                if(wood_stick->second >= min_weight) {
                    min_weight = wood_stick->second;
                    wood_stick = vec.erase(wood_stick);
                } else {
                    wood_stick++;
                }
            }
            ans++;
        }

        cout << ans << '\n';
    }
}