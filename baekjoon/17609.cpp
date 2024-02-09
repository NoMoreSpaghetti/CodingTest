#include <iostream>
using namespace std;

int T;

int check_palindrome(int left, int right, bool deleted, const string& s) {
    while(left < right) {
        if(s[left] != s[right]) {
            if(!deleted) {
                int left_result = check_palindrome(left + 1, right, true, s);
                int right_result = check_palindrome(left, right - 1, true, s);

                if(left_result == 0 || right_result == 0) {
                    return 1;
                } else {
                    return 2;
                }
            } else {
                return 2;
            }
        }
        left++;
        right--;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> T;
    while(T--) {
        cin >> s;
        cout << check_palindrome(0, s.length() - 1, false, s) << '\n';
    }
}