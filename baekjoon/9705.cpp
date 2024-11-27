#include <iostream>
#include <vector>
using namespace std;

// n개를 2개로 나눌 수 있는 가짓수
vector<long long> dp;

long long Solution(long long t) {
    long long return_val = 0;
    for(long long i=1; i <= t / 3; i++) {
        // 오름차순을 유지하기 위해 3명 모두 i만큼 준다.
        long long next_t = t - i * 3;
        if(dp[next_t] == -1) {
            dp[next_t] = (next_t + 2) / 2;
        }
        return_val += dp[next_t];
    }
    return return_val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    dp = vector<long long>(1000000, -1);

    int idx = 1;
    while(T) {
        // 1번 칸에 0개, 2번 칸에 1개, 3번 칸에 2개씩 놓고 시작
        // 이렇게 하면 같은 개수로 나눠도 오름차순
        long long ans = Solution(T - 3);

        cout << "Case #" << idx << ": " << T << ':' << ans << '\n';

        cin >> T;
        idx++;
    }
}