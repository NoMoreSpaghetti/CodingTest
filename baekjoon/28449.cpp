#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

vector<int> HI;
vector<int> ARC;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    HI = vector<int>(N, 0);
    ARC = vector<int>(M, 0);

    for(int i=0; i < N; i++) {
        cin >> HI[i];
    }
    for(int i=0; i < M; i++) {
        cin >> ARC[i];
    }

    sort(HI.begin(), HI.end());
    sort(ARC.begin(), ARC.end());

    int lower_idx = -1;
    int upper_idx = -1;
    int prev = -1;
    long long num_HI_wins = 0;
    long long num_ARC_wins = 0;
    long long num_draws = 0;

    for(int i=0; i < N; ) {
        // lower idx 구하기
        while(lower_idx + 1 < M && ARC[lower_idx + 1] < HI[i]) {
            lower_idx++;
        }

        while(upper_idx + 1 < M && ARC[upper_idx + 1] <= HI[i]) {
            upper_idx++;
        }

        // HI[i] == HI[i + 1]인 동안 대회 결과 계속 더하기
        do {
            num_HI_wins += lower_idx + 1;
            num_ARC_wins += M - upper_idx - 1;
            num_draws += upper_idx - lower_idx;
            i++;
        } while(i < N && HI[i - 1] == HI[i]);
        lower_idx = upper_idx;
    }

    cout << num_HI_wins << ' ' << num_ARC_wins << ' ' << num_draws << '\n';
}