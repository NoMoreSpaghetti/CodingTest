#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int turn_num = 0;
    bool dp[1001] = {0};

    // 1개의 경우 현재 플레이어의 패배
    // 2개인 경우 현재 플레이어의 승리
    // 3개인 경우 현재 플레이어의 패배
    // 4개인 경우 현재 플레이어의 승리
    // 5개인 경우 현재 플레이어의 승리
    // 6개인 경우 3개를 가져가면 현재 플레이어의 승리
    // 7개인 경우 4개를 가져가면 현재 플레이어의 승리
    // 8개인 경우 현재 플레이어의 패배
    // 9개인 경우 1개를 가져가면 현재 플레이어의 승리
    // 10개인 경우 현재 플레이어의 패배

    dp[1] = false;
    dp[2] = true;
    dp[3] = false;
    dp[4] = true;
    for(int i=5; i <= N; i++) {
        dp[i] = !dp[i - 1] | !dp[i - 3] | !dp[i - 4];
    }

    if(dp[N]) {
        cout << "SK" << '\n';
    } else {
        cout << "CY" << '\n';
    }
}