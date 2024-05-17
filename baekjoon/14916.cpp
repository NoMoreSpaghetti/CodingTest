#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int answer = 0;
    if(n == 1 || n == 3) {
        cout << -1 << '\n';
    } else {
        answer += n / 5;
        n %= 5;
        if(n % 2 == 0) {
            answer += n / 2;
        } else {
            answer += n / 2 + 2;
        }
        
        cout << answer << '\n';
    }
}