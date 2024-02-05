#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<int> nums(N, 0);
    for(int i=0; i < N; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int ans = 0;
    int prev = 1000000001;
    bool is_prev_good = false;
    for(int i=N - 1; i >= 0; i--) {
        int& num = nums[i];
        if(num == prev && is_prev_good) {
            ans++;
            continue;
        } else {
            is_prev_good = false;
        }

        int r = N - 1;
        int l = 0;
        if(r == i) {
            r--;
        }
        if(l == i) {
            l++;
        }

        while(l < r) {
            int sum = nums[l] + nums[r];
            if(sum < num) {
                l++;
                if(l == i) {
                    l++;
                }
            } else if(sum > num) {
                r--;
                if(r == i) {
                    r--;
                }
            } else {
                ans++;
                is_prev_good = true;
                break;
            }
        }
        prev = num;
    }

    cout << ans << '\n';
}