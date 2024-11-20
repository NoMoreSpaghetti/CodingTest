#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int func(vector<int>& nums, int idx_bit, int left, int right, int small_num, int big_num) {
    if(idx_bit == (1 << nums.size()) - 1) {
        return big_num - small_num;
    }

    while(idx_bit & (1 << left)) left++;
    while(idx_bit & (1 << right)) right--;

    if(left == right) {
        // 홀수개인 경우
        return func(nums, idx_bit | (1 << left), left, right, small_num, big_num * 10 + nums[left]);
    } else {
        return func(nums, idx_bit | (1 << left) | (1 << right), left, right, small_num * 10 + nums[right], big_num * 10 + nums[left]);
    }
}

int solution(vector<int>& nums) {
    int ans = INT32_MAX;
    int small_num = 0;
    int big_num = 0;

    if(nums.size() % 2 == 0) {
        // 짝수개면 연속된 두 수를 앞자리로 설정
        if(nums[0] == 0) {
            if(nums.size() == 2) {
                return nums[1];
            }

            for(int i=2; i < nums.size(); i++) {
                ans = min(ans, func(nums, (1 << (i - 1)) | (1 << i), 0, nums.size() - 1, nums[i - 1], nums[i]));
            }
        } else {
            for(int i=1; i < nums.size(); i++) {
                ans = min(ans, func(nums, (1 << (i - 1)) | (1 << i), 0, nums.size() - 1, nums[i - 1], nums[i]));
            }
        }
    } else {
        // 홀수개면 가장 반대편에 있는 두 수를 앞자리로 설정(0 제외)
        if(nums[0] == 0) {
            ans = func(nums, (1 << 1) | (1 << (nums.size() - 1)), 0, nums.size() - 2, nums[nums.size() - 1], nums[1]);
        } else {
            ans = func(nums, 1 | (1 << (nums.size() - 1)), 1, nums.size() - 2, nums[nums.size() - 1], nums[0]);
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    cin.ignore();

    while(T--) {
        vector<int> nums;
        string inp_s, num_str;
        int num;

        getline(cin, inp_s);

        stringstream ss(inp_s);

        while(getline(ss, num_str, ' ')) {
            nums.push_back(stoi(num_str));
        }

        cout << solution(nums) << '\n';
    }
}