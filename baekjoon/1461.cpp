#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    vector<int> bookshelf(N, 0);
    for(int i=0; i < N; i++) {
        cin >> bookshelf[i];
    }

    int ans = 0;
    sort(bookshelf.begin(), bookshelf.end());
    int positive_num_start_idx = lower_bound(bookshelf.begin(), bookshelf.end(), 0) - bookshelf.begin();

    for(int i=0; i < positive_num_start_idx; i += M) {
        ans += abs(bookshelf[i]) * 2;
    }

    for(int i=N - 1; i >= positive_num_start_idx; i -= M) {
        ans += abs(bookshelf[i]) * 2;
    }

    ans -= max(abs(bookshelf[0]), abs(bookshelf[N - 1]));
    cout << ans << '\n';
}