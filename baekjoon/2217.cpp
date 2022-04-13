#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> ropes(N);

    for(int i=0; i < N; i++) {
        cin >> ropes[i];
    }

    sort(ropes.begin(), ropes.end(), greater<int>());

    int answer = 0;
    for(int i=0; i < ropes.size(); i++) {
        if(ropes[i] * (i + 1) > answer) {
            answer = ropes[i] * (i + 1);
        }
    }

    cout << answer << '\n';
}