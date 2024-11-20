#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double C;
    int num_striks, N;

    cin >> C >> N;
    vector<int> vec(N, 0);
    vector<int> sum;

    int num_coins = min(2.0, C / 0.99);
    int max_num = 0;

    for(int i=0; i < N; i++) {
        cin >> vec[i];
        max_num = max(max_num, vec[i]);
    }

    for(int i=0; i < N; i++) {
        if(vec[i] == 0) {
            sum.push_back(0);
            continue;
        }

        int num_nonzero = 0;
        while(i < N && vec[i] != 0) {
            num_nonzero++;
            i++;
        }
        sum.push_back(num_nonzero);
        if(i < N) {
            sum.push_back(0);
        }
    }

    vector<vector<int>> dp(sum.size() + 1, vector<int>(2, 0));
    vector<int> max_vals(3, 0);

    for(int i=0; i < sum.size(); i++) {
        max_vals[0] = max(max_vals[0], sum[i]);
        if(sum[i] == 0) {
            max_vals[1] = max(max_vals[1], dp[i][0]);
            max_vals[2] = max(max_vals[2], dp[i][1]);
            dp[i + 1][0] = (i > 0) ? sum[i - 1] + 1 : 1;
            dp[i + 1][1] = dp[i][0] + 1;
        } else {
            dp[i + 1][0] = dp[i][0] + sum[i];
            dp[i + 1][1] = dp[i][1] + sum[i];
        }
    }

    max_vals[1] = max(max_vals[1], dp[sum.size()][0]);
    max_vals[2] = max(max_vals[2], dp[sum.size()][1]);

    int longest_len = max_vals[0];
    for(int i=1; i <= num_coins; i++) {
        longest_len = max(longest_len, max_vals[i]);
    }

    cout << longest_len << '\n' << max_num << '\n';
}