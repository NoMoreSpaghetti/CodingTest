#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, C;
    string s;

    while(getline(cin, s)) {
        istringstream iss(s);

        string str_num;
        vector<int> nums;
        while(getline(iss, str_num, ' ')) {
            nums.push_back(stoi(str_num));
        }

        int ans = max(nums[1] - nums[0], nums[2] - nums[1]) - 1;
        cout << ans << '\n';
    }
}