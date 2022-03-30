#include <iostream>
#include <vector>
using namespace std;

int dp[1000001] = {0};
vector<int> six_nums;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int six_num = 1;
    for(int i=1; six_num <= n; i++) {
        six_nums.push_back(six_num);
        six_num += (4 * i + 1);
        dp[six_num] = 1;   
    }
    six_nums.push_back(six_num);

    for(int i=1; i <= n; i++) {
        dp[i] = 6;
        for(int j=0; six_nums[j] <= i; j++) {
            if(dp[i] > dp[i - six_nums[j]]) {
                dp[i] = dp[i - six_nums[j]] + 1;
            }
        }
    }
    
    cout << dp[n] << '\n';
}