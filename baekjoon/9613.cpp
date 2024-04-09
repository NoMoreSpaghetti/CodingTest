#include <iostream>
#include <vector>
using namespace std;

long long get_gcd(long long a, long long b) {
    long long c;

    while(b != 0) {
        c = a % b;
        a = b;
        b = c;        
    }

    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    cin >> t;

    while(t--) {
        cin >> n;
        vector<long long> nums(n, 0);
        for(int i=0; i < n; i++) {
            cin >> nums[i];
        }

        long long ans = 0;
        for(int i=0; i < n - 1; i++) {
            for(int j=i + 1; j < n; j++) {
                ans += get_gcd(nums[i], nums[j]);
            }
        }
        cout << ans << '\n';
    }
}