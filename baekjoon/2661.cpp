#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N;
string s;

bool check_good_arr(const string& target_s) {
    const int n = target_s.length();

    // 길이가 2 이상인 경우부터 검사
    for(int i=2; i <= n / 2; i++) {
        if(target_s.substr(n - 2 * i , i) == target_s.substr(n - i, i)) {
            return false;
        }
    }
    return true;
}

bool recursive() {
    if(s.length() == N) {
        return true;
    }

    for(char i='1'; i <= '3'; i++) {
        if(s.back() == i) {
            continue;
        }
        s += i;
        if(check_good_arr(s) && recursive()) {
            return true;
        }
        s.pop_back();
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    s = "1";

    recursive();

    cout << s << '\n';
}