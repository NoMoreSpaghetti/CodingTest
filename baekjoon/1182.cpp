#include <iostream>
#include <algorithm>
using namespace std;

int N, S;
int ary[20];
int ans = 0;

void recursive(int n, int sum) {
    for(int i=n; i < N; i++) {
        int new_sum = sum + ary[i];
        if(new_sum == S) {
            ans++;
        }
        recursive(i + 1, new_sum);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S;
    for(int i=0; i < N; i++) {
        cin >> ary[i];
    }

    sort(ary, ary + N);

    recursive(0, 0);
    cout << ans << '\n';
}