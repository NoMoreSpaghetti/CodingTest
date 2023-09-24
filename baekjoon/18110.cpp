#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    if(n > 0) {
        vector<int> difficulty(n, 0);
        int cut_num = round(n * 0.15);

        for(int i=0; i < n; i++) {
            cin >> difficulty[i];
        }

        sort(difficulty.begin(), difficulty.end());

        int mean = round(accumulate(difficulty.begin() + cut_num, difficulty.end() - cut_num, 0.0) / (difficulty.size() - cut_num * 2));
        cout << mean << endl;

    } else {
        cout << 0 << endl;
    }
}