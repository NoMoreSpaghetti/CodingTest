#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, S;
    int ary[100000];
    cin >> N >> S;

    for(int n=0; n < N; n++) {
        cin >> ary[n];
    }

    int left = 0, right = 1, sum = ary[0], min_len = N+1;

    while(right <= N) {
        if(right == left || sum < S) {
            sum += ary[right];
            right++;
        } else {
            if(min_len > right - left) {
                min_len = right - left;
            }
            sum -= ary[left];
            left++;
        }
    }

    if(min_len == N+1) {
        cout << 0 << '\n';
    } else {
        cout << min_len << '\n';
    }
}