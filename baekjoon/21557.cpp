#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> fireworks(N, 0);
    for(int i=0; i < N; i++) {
        cin >> fireworks[i];
    }

    // 양 끝의 폭죽이 남음
    // N은 3이상 - 마지막 폭죽은 양 끝의 폭죽을 모두 1씩 감소시킴
    // 폭죽 높이는 N이상. 옆의 폭죽이 터져서 현재 폭죽이 사라지는 경우는 없음
    int front = fireworks[0] - 1;
    int back = fireworks[N - 1] - 1;

    int remain_num = N - 3;

    int avg = (front + back - remain_num + 1) / 2;

    int answer = avg;
    if(front < avg) {
        answer = back - remain_num;
    } else if(back < avg) {
        answer = front - remain_num;
    }

    cout << answer << '\n';
}