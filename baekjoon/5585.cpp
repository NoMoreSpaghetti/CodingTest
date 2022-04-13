#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    n = 1000 - n;

    int coins[6] = {500, 100, 50, 10, 5, 1};
    int answer = 0;

    for(int i=0; i < 6; i++) {
        answer += n / coins[i];
        n %= coins[i];
    }

    cout << answer << '\n';
}