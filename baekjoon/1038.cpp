#include <iostream>
#include <cstring>
using namespace std;


string get_first_num(int size) {
    string ret = "";
    for(int i=size - 1; i >= 0; i--) {
        ret += to_string(i);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    if(N < 10) {
        cout << N << '\n';
    } else {
        string answer = "";

        N -= 10;

        // i: 숫자 길이
        int i=2;
        for(; i <= 10; i++) {
            // 숫자 길이에 맞는 초기값 지정
            answer = get_first_num(i);

            int first_num = answer[0];
            int idx = i - 1;

            while(true) {
                // N이 0이면 정답 출력
                if(N == 0) {
                    cout << answer << '\n';
                    return 0;
                }

                // 자릿수 올라가면서 어디서 값을 증가시킬 수 있는지 검사
                while(idx - 1 >= 0 && answer[idx] + 1 == answer[idx - 1]) {
                    idx -= 1;
                }
                
                if(idx == 0) {
                    // 맨 앞자리 숫자 조정
                    if(answer[0] < '9') {
                        answer = get_first_num(i);
                        answer[0] = ++first_num;
                    } else {
                        // 숫자 길이 늘리기
                        N--;
                        break;
                    }
                } else {
                    answer = answer.substr(0, idx + 1) + get_first_num(i - idx - 1);
                    answer[idx]++;
                }
                idx = i - 1;
                N--;
            }
        }
        if(i > 10) {
            cout << -1 << '\n';
        }
    }
}