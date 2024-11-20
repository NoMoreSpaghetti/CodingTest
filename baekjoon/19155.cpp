#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N, 0);

    for(int i=0; i < N; i++) {
        cin >> A[i];
        cout << N - A[i] + 1 << ' ';
    }
    cout << '\n';
}