#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, A, B, C;
    cin >> T;
    while(T--) {
        cin >> A >> B >> C;
        bool ans = true;
        
        // 타일 회전 불가
        // ㄴ자 타일 개수보다 많은 1x1 타일 필요
        if(A < C) {
            ans = false;
        } else if((A + C) % 2 == 1) {
            // ㄴ자 타일과 1x1 타일을 합친 개수가 짝수여야 함
            ans = false;
        } else if(A == 0 && C == 0 && B % 2 == 1) {
            // A와 C가 없는데 B가 홀수개면 불가
            ans = false;
        }
        if(ans) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
}