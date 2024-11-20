#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> nums;

// int solution(vector<int>& selected_nums, int idx) {
//     if(selected_nums.size() == 4) {
//         return abs(selected_nums[0] + selected_nums[3] - selected_nums[1] - selected_nums[2]);
//     }

//     int return_val = INT32_MAX;
//     for(int i=idx; i < N; i++) {
//         selected_nums.push_back(nums[i]);
//         int 
//         return_val = min(return_val, solution(selected_nums, i + 1));
//         selected_nums.pop_back();
//     }

//     return return_val;
// }

int solution() {
    int ans = INT32_MAX;

    for(int left=0; left < N; left++) {
        for(int right=N - 1; right >= 0; right--) {
            int snowman1 = nums[left] + nums[right];

            int left2 = left + 1;
            int right2 = right - 1;

            while(left2 < right2) {
                int snowman2 = nums[left2] + nums[right2];
                int cur_diff = snowman1 - snowman2;
                if(cur_diff > 0) {
                    left2++;
                } else {
                    right2--;
                }

                ans = min(ans, abs(cur_diff));
            }
        }        
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    nums = vector<int>(N, 0);

    for(int i=0; i < N; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    vector<int> selected_nums;
    cout << solution() << '\n';
}