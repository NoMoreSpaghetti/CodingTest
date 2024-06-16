#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> vec(N, 0);
    for(int i=0; i < N; i++) {
        cin >> vec[i];
    }

    int idx = 1;
    for(int i=0; i < N; i++) {
        while(idx < N && vec[i] == vec[idx]) {
            idx++;
        }
        if(idx == N) {
            cout << -1 << ' ';
        } else {
            cout << idx + 1 << ' ';
        }
    }
}