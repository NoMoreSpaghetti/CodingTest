#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, inp;
    cin >> N;

    vector<long long> nums(3, 0);

    for(int i=0; i < N; i++) {
        cin >> inp;
        inp = min(inp, 2);
        nums[inp]++;
    }
    
    // 0, 0일 때 mex는 1
    long long ans = (nums[0] * (nums[0] - 1)) >> 1;
    ans += 2 * nums[0] * nums[1];
    ans += nums[0] * nums[2];

    cout << ans << '\n';
}