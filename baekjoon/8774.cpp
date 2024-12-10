#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Z, N, k;

    cin >> Z;

    for(int z=0; z < Z; z++) {
        cin >> N;
        vector<int> results(N, -1);
        stack<pair<int, int>> s;
        for(int i=0; i < N; i++) {
            cin >> k;

            while(!s.empty() && k > s.top().first) {
                results[s.top().second] = i;
                s.pop();
            }
            s.push({k, i});
        }

        for(const auto& num : results) {
            cout << num << ' ';
        }
        cout << '\n';
    }
}