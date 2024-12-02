#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, D;
    cin >> N >> M >> D;

    int ans = 0;

    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            int cur_state = 0;

            // 왼쪽 위
            if(i + j < D) {
                cur_state = 1;
            }

            // 오른쪽 위
            if(i + (M - 1 - j) < D && cur_state == 1) {
                cur_state = 2;
            }

            // 왼쪽 아래
            if((N - 1 - i) + j < D && cur_state == 2) {
                cur_state = 3;
            }

            // 오른쪽 아래
            if((N - 1 - i) + (M - 1 - j) < D && cur_state == 3) {
                ans++;
            }
        }
    }

    cout << ans << '\n';
}