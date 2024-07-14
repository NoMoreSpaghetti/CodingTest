#include <iostream>
#include <vector>
using namespace std;

int N, K;

vector<int> scores;
vector<int> healths;
vector<vector<int>> dp;


int pack(int health, int idx) {
    if(idx == N) {
        return 0;
    }

    int& ret = dp[health][idx];

    if(ret != -1) {
        return ret;
    }

    // 이 파트를 진행하지 않을 경우
    ret = pack(min(100, health + K), idx + 1);

    if(healths[idx] <= health) {
        ret = max(ret, pack(min(100, health + K - healths[idx]), idx + 1) + scores[idx]);
    }
    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    scores = vector<int>(N, 0);
    healths = vector<int>(N, 0);

    for(int i=0; i < N; i++) {
        cin >> scores[i];
    }

    for(int i=0; i < N; i++) {
        cin >> healths[i];
    }

    dp = vector<vector<int>>(101, vector<int>(N, -1));
    
    cout << pack(100, 0) << '\n';

}