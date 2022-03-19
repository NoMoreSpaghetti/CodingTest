// 참고: https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=alwaysneoi&logNo=100155502982

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, answer = 0;
    cin >> N;

    if(N == 1) {
        answer = 1;
    } else {
        if(N % 2 == 0) {
            answer = N * (N + 2) * (2 * N + 1) / 8;
        } else {
            answer = (N + 1) * (2 * N * N + 3 * N - 1) / 8;
        }
    }

    cout << answer << '\n';
}