#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, a, b, c;
    cin >> N;

    int ans = 0;
    vector<int> nums(1000001, 0);

    for(int i=0; i < N; i++) {
        for(int j=0; j < 3; j++) {
            cin >> a >> b >> c;
            if(nums[a] == 0 && nums[b] == 0 && nums[c] == 0) {
                ans++;
            }
            nums[a]++;
            nums[b]++;
            nums[c]++;
        }
    }

    cout << ans << '\n';
}