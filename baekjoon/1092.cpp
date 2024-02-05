#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<int> crane_limits(N, 0);
    vector<int> crane_positions(N, 0);

    for(int i=0; i < N; i++) {
        cin >> crane_limits[i];
    }

    cin >> M;
    vector<int> box_weights(M, 0);
    for(int i=0; i < M; i++) {
        cin >> box_weights[i];
    }

    sort(crane_limits.begin(), crane_limits.end(), greater<int>());
    sort(box_weights.begin(), box_weights.end(), greater<int>());
    
    // 해결 불가능한 경우
    if(crane_limits[0] < box_weights[0]) {
        cout << -1 << '\n';
        return 0;
    }

    // 이분 탐색으로 크레인 위치 정해놓기
    for(int i=0; i < N; i++) {
        int& crane_limit = crane_limits[i];
        int idx = lower_bound(box_weights.begin(), box_weights.end(), crane_limit, greater<int>()) - box_weights.begin();
        crane_positions[i] = idx;
    }
    
    int time = 0;
    int num_moved = 0;
    while(num_moved < M) {
        for(int i=0; i < N; i++) {
            int& crane_limit = crane_limits[i];
            int& crane_pos = crane_positions[i];
            while(crane_pos < M && box_weights[crane_pos] == -1) {
                crane_pos++;
            }
            if(crane_pos < M) {
                box_weights[crane_pos++] = -1;
                num_moved++;
            }
        }
        time++;
    }
    cout << time << '\n';
}