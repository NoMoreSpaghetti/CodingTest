#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> pic(N, vector<int>(M, 0));
    int ans = 0;

    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            cin >> pic[i][j];
        }

        for(int j=0; j < M; j++) {
            // 0이 입력되면 분리된 영역
            // 덧칠이 가능

            if(pic[i][j] != 0) {
                int num_area = 1;
                int cur_val = pic[i][j];
                j++;
                while(j < M && pic[i][j]) {
                    // 다음 값이 0이 아니고
                    // 현재값과 다음 값이 다른 동안
                    if(pic[i][j] != cur_val) {
                        num_area++;
                    }
                    cur_val = pic[i][j];
                    j++;
                }

                // 다음 값이 0이거나
                // 오른쪽 끝에 도달하면
                ans += (num_area + 2) / 2;
            }
        }
    }

    cout << ans << '\n';
}