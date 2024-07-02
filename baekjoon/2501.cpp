#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    vector<int> vec;
    cin >> N >> K;

    int ans = 0;
    int i = 1;
    for(; i * i < N; i++) {
        if(N % i == 0) {
            vec.push_back(i);
            vec.push_back(N / i);
        }
    }
    if(i * i == N) {
        vec.push_back(i);
    }

    sort(vec.begin(), vec.end());

    if(vec.size() < K) {
        cout << 0 << '\n';
    } else {
        cout << vec[K - 1] << '\n';
    }
}