#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> A(N, 0);
    vector<int> max_vals(N, 0);
    for(int i=0; i < N; i++) {
        cin >> A[i];
    }

    max_vals[N - 1] = A[N - 1];
    for(int i=1; i <= M; i++) {
        max_vals[N - 1 - i] = max(max_vals[N - i], A[N - 1 - i]);
    }

    // 오른쪽에 가장 큰 값이 가고 왼쪽에 가장 작은 값이 가야 함

    int ans = A[N - 1] - A[0];
    for(int i=0; i <= M; i++) {
        ans = max(ans, max_vals[N - 1 - (M - i)] - A[i]);
    }
    
    cout << ans << '\n';
}