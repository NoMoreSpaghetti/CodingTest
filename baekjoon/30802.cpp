#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, T, P;
    vector<int> sizes(6, 0);
    cin >> N;
    for(int i=0; i < 6; i++) {
        cin >> sizes[i];
    }
    cin >> T >> P;

    int answer = 0;
    for(const auto& size : sizes) {
        answer += (size + T - 1) / T;
    }
    cout << answer << '\n';
    cout << N / P << ' ' << N % P << '\n';
}