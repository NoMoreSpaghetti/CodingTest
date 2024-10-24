#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> times(N + 1, 0);
    vector<int> cumulative_times(N + 2, 0);
    vector<vector<int>> soldiers(M, vector<int>(3, 0));

    cin >> times[1];
    for(int i=2; i <= N; i++) {
        cin >> times[i];
        cumulative_times[i] = times[i - 1] + cumulative_times[i - 1];
    }
    cumulative_times[N + 1] = times[N] + cumulative_times[N];

    for(int i=0; i < M; i++) {
        cin >> soldiers[i][0] >> soldiers[i][1] >> soldiers[i][2];
    }

    int times_sum = cumulative_times[N + 1];
    int time = 0;
    int ans = 0;

    for(int i=0; i < M; i++) {
        // 순환 횟수 * 전체 순환 소요시간
        time = (soldiers[i][2] / times_sum) * times_sum;

        // 1 2 3 4 5  6
        // 0 1 4 6 10 13
        // 출발 시간, 도착 시간
        int boarding_time = time + cumulative_times[soldiers[i][0]];
        if(soldiers[i][2] > boarding_time) {
            time += times_sum;
            boarding_time += times_sum;
        }

        if(soldiers[i][1] < soldiers[i][0]) {
            time += times_sum;
        }

        int arrival_time = time + cumulative_times[soldiers[i][1]];
        ans = max(ans, arrival_time);
    }
    
    cout << ans << '\n';
}