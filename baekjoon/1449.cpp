#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L, inp;
    cin >> N >> L;

    vector<int> positions;

    for(int i=0; i < N; i++) {
        cin >> inp;
        positions.push_back(inp);
    }

    sort(positions.begin(), positions.end());

    int tape_end_pos, num_tape= 0;
    for(int i=0; i < positions.size();) {
        tape_end_pos = positions[i] + L;
        num_tape++;
        i++;
        while(i < positions.size() && positions[i] < tape_end_pos) {
            i++;
        }
    }

    cout << num_tape << '\n';
}