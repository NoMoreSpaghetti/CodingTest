#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, inp;
    vector<int> liquids;
    cin >> N;

    for(int i=0; i < N; i++) {
        cin >> inp;
        liquids.push_back(inp);
    }

    sort(liquids.begin(), liquids.end());

    int front = 0, end = liquids.size() - 1;
    int liquid_A_idx, liquid_B_idx;
    int dif, min_dif = INT32_MAX;

    while(front < end) {
        int dif = liquids[end] + liquids[front];

        if(abs(dif) < min_dif) {
            min_dif = abs(dif);
            liquid_A_idx = front;
            liquid_B_idx = end;
        }

        if(dif > 0) {
            end--;
        } else {
            front++;
        }
    }

    cout << liquids[liquid_A_idx] << ' ' << liquids[liquid_B_idx] << '\n';
}