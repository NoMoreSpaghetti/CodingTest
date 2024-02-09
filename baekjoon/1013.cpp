#include <iostream>
using namespace std;

bool check_string(int pattern_id, int cur_idx, const string& s) {
    if(cur_idx == s.length()) {
        return false;
    }
    if(pattern_id == '0') {
        // 01로 시작하는 경우
        if(s[cur_idx] != '1') {
            return false;
        }
        cur_idx++;
        if(cur_idx == s.length()) {
            return true;
        }
        return check_string(s[cur_idx], cur_idx + 1, s);

    } else {
        // 100+1+로 시작하는 경우

        int num_sames = 0;
        while(cur_idx < s.length() && s[cur_idx] == '0') {
            cur_idx++;
            num_sames++;
        }
        if(num_sames < 2 || cur_idx == s.length()) {
            return false;
        }

        // 현재 cur_idx 위치에는 1
        cur_idx++;
        num_sames = 1;
        while(cur_idx < s.length() && s[cur_idx] == '1') {
            cur_idx++;
            num_sames++;
        }

        if(cur_idx == s.length()) {
            return true;
        }
        if(num_sames > 1) {
            return check_string(s[cur_idx], cur_idx + 1, s) || check_string(s[cur_idx - 1], cur_idx, s);
        } else {
            return check_string(s[cur_idx], cur_idx + 1, s);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    string s;
    while(T--) {
        cin >> s;
        if(check_string(s[0], 1, s)) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}