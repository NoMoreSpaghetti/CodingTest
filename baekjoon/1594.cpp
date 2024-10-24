#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N;
string inp_s;
vector<int> nums;

string ans = "";
int max_score = -1;
vector<int> score_dp;

void GetAns(string s, int cur, int score) {
    // cout << "score : " << score << '\n';
    if(score_dp[cur - 1] >= score) {
        return;
    }

    score_dp[cur - 1] = score;

    if(cur == N + 1) {
        // cout << score << '\n';
        if(max_score < score) {
            max_score = score;
            ans = s;
        }
        return;
    }

    if(cur + 1 > N) {
        return;
    }

    string cur_s = "";
    int cur_nums = 0;
    int cur_bit = 0;
    for(int i=cur; i < cur + 2; i++) {
        cur_s += inp_s[i];
        if((cur_bit & (1 << nums[i])) == 0) cur_nums++;
        cur_bit |= (1 << nums[i]);
    }

    cur += 2;
    GetAns(s + "-" + cur_s, cur, score + ((cur_nums == 2) ? 0 : 2));

    if(cur > N) {
        return;
    }

    if((cur_bit & (1 << nums[cur])) == 0) cur_nums++;
    cur_s += inp_s[cur];
    cur++;
    GetAns(s + "-" + cur_s, cur, score + 3 - cur_nums);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> inp_s;
    N = inp_s.length();
    nums = vector<int>(N + 1, 0);
    score_dp = vector<int>(N + 1, -1);

    // 시작을 1로 맞춰주기
    inp_s = " " + inp_s;
    for(int i=1; i <= N; i++) {
        nums[i] = inp_s[i] - '0';
    }

    GetAns("", 1, 0);

    cout << ans.substr(1, ans.length() - 1);

}