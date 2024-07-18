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
    vector<int> books(N, 0);
    for(int i=0; i < N; i++) {
        cin >> books[i];
    }

    sort(books.begin(), books.end());

    int ans = 1;
    int limit = (books[0] << 1);
    for(int i=1; i < N; i++) {
        if(books[i] >= limit) {
            limit = (books[i] << 1);
            ans++;
        }
    }

    cout << ans << '\n';
}