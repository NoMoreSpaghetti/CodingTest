#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    string ans = "";

    for(int i=0; i < N; i++) {
        ans += 'a';
    }

    char last_char = 'a' + K - 1;
    for(int i=0; i < K; i++) {
        ans[N - 1 - i] = last_char--;
    }

    cout << ans << '\n';
}