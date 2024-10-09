#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;

string str1 = "Messi";
string str2 = "Messi Gimossi";

char recursive(int idx, int dp_idx) {

    if(idx < str2.length()) {
        return str2[idx];
    }

    if(idx > dp[dp_idx - 1]) {
        return recursive(idx - dp[dp_idx - 1] - 1, dp_idx - 2);
    } else if(idx == dp[dp_idx - 1]) {
        return ' ';
    } else {
        return recursive(idx, dp_idx - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M;
    cin >> M;

    dp.push_back(0);
    dp.push_back(str1.length());
    dp.push_back(str2.length());

    for(int i=3; dp.back() < M; i++) {
        dp.push_back(dp[i - 1] + dp[i - 2] + 1);
    }

    char answer = recursive(M - 1, dp.size() - 1);
    if(answer != ' ') {
        cout << answer << '\n';
    } else {
        cout << "Messi Messi Gimossi" << '\n';
    }
}