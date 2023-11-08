
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N;
    cin >> T;
    while(T--) {
        cin >> N;
        vector<int> logs = vector<int>(N, 0);
        for(int i=0; i < N; i++) {
            cin >> logs[i];
        }

        sort(logs.begin(), logs.end());

        int max_difficulty = 0;
        int difficulty;
        for(int start_i=2; start_i <= 3; start_i++) {
            for(int i=start_i; i < logs.size(); i += 2) {
                difficulty = abs(logs[i] - logs[i - 2]);
                if(difficulty > max_difficulty) {
                    max_difficulty = difficulty;
                }
            }
        }

        cout << max_difficulty << '\n';
    }
}