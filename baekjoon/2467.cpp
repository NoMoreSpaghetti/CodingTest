#include <iostream>
#include <limits.h>
using namespace std;

int N;
int nums[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int n=0; n < N; n++) {
        cin >> nums[n];
    }

    int left = 0;
    int right = N-1;

    int min_sum = INT_MAX;
    int left_val, right_val;

    while(left < right) {
        int new_sum = abs(nums[left] + nums[right]);
        if(new_sum < min_sum) {
            left_val = nums[left];
            right_val = nums[right];
            min_sum = new_sum;
        }
        if(abs(nums[left]) < abs(nums[right])) {
            right--;
        } else {
            left++;
        }
    }

    cout << left_val << ' ' << right_val << '\n';
}