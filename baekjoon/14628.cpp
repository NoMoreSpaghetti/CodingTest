#include <iostream>
#include <vector>
#define MAX (505001)
using namespace std;

int N, M, K;
int Xs[101];
int Ys[101];
int dp[101][101];

int use_skill(int health, int skill) {
    if(health == 0) {
        return 0;
    } else if(skill == N) {
        return MAX;
    } else {
        int& ret = dp[health][skill];
        if(ret != MAX) {
            return ret;
        } else {
            for(int i=0; Ys[skill] * i <= health; i++) {
                ret = min(ret, use_skill(health - Ys[skill] * i, skill + 1) + Xs[skill] * i + (K * ((i - 1) * i) / 2));
            }
        }

        return ret;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&dp[0][0], &dp[100][101], MAX);

    cin >> N >> M >> K;
    for(int i=0; i < N; i++) {
        cin >> Xs[i] >> Ys[i];
    }

    cout << use_skill(M, 0) << '\n';
}