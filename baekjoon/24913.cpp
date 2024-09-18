#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q, op;
    long long x, y;
    cin >> N >> Q;

    vector<long long> candidates(N + 1, 0);
    long long sum = 0;
    long long max_val = 0;

    while(Q--) {
        cin >> op >> x >> y;
        if(op == 1) {
            candidates[y - 1] += x;
            if(y - 1 != N) {
                sum += x;
                max_val = max(max_val, candidates[y - 1]);
            }
        } else {
            if((sum + y - 1) / N + 1 < candidates[N] + x && max_val < candidates[N] + x) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }
}