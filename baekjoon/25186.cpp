#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, sum = 0;
    cin >> N;
    vector<long long> clothes(N, 0);

    for(int i=0; i < N; i++) {
        cin >> clothes[i];
        sum += clothes[i];
    }

    sort(clothes.begin(), clothes.end(), greater<int>());

    if(sum == 1) {
        cout << "Happy" << '\n';
    } else {
        if(clothes[0] > sum / 2) {
            cout << "Unhappy" << '\n';
        } else {
            cout << "Happy" << '\n';
        }
    }
}