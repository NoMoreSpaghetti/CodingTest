#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;

map<char, int> score_map = {{'o', 100}, {'e', 10}, {'g', 1}, {'a', 0}, {'b', -1}, {'i', -10}, {'u', -100}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s = "", inp;
    vector<int> scores_dp;

    // 입력 처리
    cin >> inp;
    while(inp.back() != '.') {
        s += inp;
        cin >> inp;
    }
    s += inp.substr(0, inp.size() - 1);

    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    istringstream iss(s);
    string buffer;

    while(getline(iss, buffer, ',')) {
        if(buffer.size() == 0) {
            cout << 0 << '\n';
            continue;
        }

        scores_dp = vector<int>(buffer.size() + 1, 0);
        scores_dp[0] = score_map[buffer[0]];
        for(int i=1; i < buffer.size(); i++) {
            scores_dp[i] = max(scores_dp[i - 1] + score_map[buffer[i]], score_map[buffer[i]]);
        }

        int ans = max(*max_element(scores_dp.begin(), scores_dp.end()), 0);
        cout << ans << '\n';
    }
}