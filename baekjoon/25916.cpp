#include <iostream>
#include <vector>
using namespace std;

int N, M;

vector<int> holes;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    holes = vector<int>(N, 0);

    for(int i=0; i < N; i++) {
        cin >> holes[i];
    }

    int left = 0;
    int right = 0;
    int sum = 0;
    int ans = 0;

    while(right < N) {
        sum += holes[right++];

        while(sum > M) {
            sum -= holes[left];
            left++;
        }

        ans = max(ans, sum);
    }

    cout << ans << '\n';
}