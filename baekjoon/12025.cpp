#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long k;
    string s;

    cin >> s >> k;

    // 0부터 시작하도록 수정
    k--;

    string ans = s;
    for(int i = s.length() - 1; i >= 0; i--) {
        char& cur_char = ans[i];

        // s[i]가 1, 6, 2, 7이 아니면 그냥 정답에 입력
        if(!(s[i] != '1' && s[i] != '6' && s[i] != '2' && s[i] != '7')) {
            if(s[i] - 5 >= '1') {
                // s[i]가 6, 7인 경우
                if((k % 2) == 0) {
                    // 1, 2로 바꿔서
                    cur_char -= 5;
                }
            } else {
                // s[i]가 1, 2인 경우
                if((k % 2) == 1) {
                    // 6, 7로 바꿔서
                    cur_char += 5;
                }
            }
            k >>= 1;
        }
    }

    if(k > 0) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
}