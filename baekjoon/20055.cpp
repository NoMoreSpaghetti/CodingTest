#include <iostream>
#include <vector>
using namespace std;

int N, K;

struct Belt {
    int remain_num;
    bool robot;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    int size = N * 2;
    vector<Belt> belts(size, Belt{0, false});

    for(int i=0; i < N * 2; i++) {
        cin >> belts[i].remain_num;
    }

    int start_idx = 0;
    int end_idx = N - 1;
    
    int num_k = 0;
    int ans = 1;

    while(true) {
        // 1번 과정
        start_idx = (start_idx - 1 + size) % size;
        end_idx = (end_idx - 1 + size) % size;

        // 로봇이 내리는 위치에 도달했으면 내리기
        if(belts[end_idx].robot == true) {
            belts[end_idx].robot = false;
        }

        // 2번 과정
        // N - 2 위치에서 로봇 이동
        // 이동 가능하면 로봇 내리기
        int idx = (start_idx + N - 2) % size;
        int next_idx = (idx + 1) % size;
        if(belts[idx].robot == true && belts[next_idx].remain_num > 0) {
            belts[next_idx].remain_num--;
            belts[idx].robot = false;
            if(belts[next_idx].remain_num == 0) {
                num_k++;
            }
        }

        // 0 ~ N - 3 위치에 있는 로봇 이동
        for(int i=N - 3; i >= 0; i--) {
            idx = (idx - 1 + size) % size;
            next_idx = (next_idx - 1 + size) % size;
            if(belts[idx].robot == true && belts[next_idx].robot == false && belts[next_idx].remain_num > 0) {
                belts[next_idx].remain_num--;
                belts[idx].robot = false;
                belts[next_idx].robot = true;
                if(belts[next_idx].remain_num == 0) {
                    num_k++;
                }
            }
        }

        // 3번 과정
        if(belts[start_idx].remain_num > 0) {
            belts[start_idx].robot = true;
            belts[start_idx].remain_num--;
            if(belts[start_idx].remain_num == 0) {
                num_k++;
            }
        }

        // 4번 과정
        if(num_k >= K) {
            break;
        }

        ans++;
    }

    cout << ans << '\n';
}