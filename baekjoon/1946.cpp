#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, rank1, rank2;
    cin >> T;

    while(T--) {
        vector<pair<int, int>> vec;
        int answer = 0;
        cin >> N;
        for(int i=0; i < N; i++) {
            cin >> rank1 >> rank2;
            vec.push_back({rank1, rank2});
        }

        sort(vec.begin(), vec.end());
        int min_r2 = 100001;
        for(auto& element: vec) {
            if(element.second < min_r2) {
                min_r2 = element.second;
                answer++;
            }
        }

        cout << answer << '\n';
    }
}