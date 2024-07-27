#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<int> vec(N + 1, 0);

    vec[0] = 0;
    for(int i=1; i <= N; i++) {
        cin >> vec[i];
        vec[i] += vec[i - 1];
    }

    int ans = 0;
    int left = 0, right = 1;

    while(right <= N) {
        int sum = vec[right] - vec[left];
        if(sum == M) {
            ans++;
            left++;
            right++;
        } else if(sum < M) {
            right++;
        } else {
            left++;
        }
    }
    
    cout << ans << '\n';
}