#include <iostream>
#include <tuple>
#include <cstring>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, strike, ball;
    string s_num;
    cin >> n;

    bool availables[999] = {0};
    memset(availables, true, sizeof(availables));

    for(int i=123; i < 999; i++) {
        string s_num = to_string(i);
        if(s_num[1] == '0' || s_num[2] == '0') {
            availables[i] = false;
        } else if(s_num[0] == s_num[1] || s_num[0] == s_num[2] || s_num[1] == s_num[2]) {
            availables[i] = false;
        }
    }

    for(int i=0; i < n; i++) {
        cin >> s_num >> strike >> ball;

        for(int j=123; j < 999; j++) {
            int temp_strike = 0, temp_ball = 0;
            
            if(availables[j]) {
                string num = to_string(j);
                for(int a=0; a < 3; a++) {
                    for(int b=0; b < 3; b++) {
                        if(num[a] == s_num[b]) {
                            if(a == b) {
                                temp_strike++;
                            } else {
                                temp_ball++;
                            }
                        }
                    }
                }
                if(temp_strike != strike || temp_ball != ball) {
                    availables[j] = false;
                }
            }
        }

    }

    int answer = 0;
    for(int i=123; i < 988; i++) {
        if(availables[i]) {
            answer++;
        }
    }
    cout << answer << '\n';
}