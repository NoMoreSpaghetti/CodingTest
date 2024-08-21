#include <iostream>
#include <vector>
using namespace std;

int get_area_sum(vector<vector<int>> &cumulative_sum, int top_y, int top_x, int bottom_y, int bottom_x) {
    return cumulative_sum[bottom_y][bottom_x] - cumulative_sum[top_y - 1][bottom_x] - cumulative_sum[bottom_y][top_x - 1] + cumulative_sum[top_y - 1][top_x - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> square(N + 1, vector<int>(M + 1, 0));
    vector<vector<int>> cumulative_sum(N + 1, vector<int>(M + 1, 0));

    for(int i=1; i <= N; i++) {
        for(int j=1; j <= M; j++) {
            cin >> square[i][j];
        }
    }

    for(int i=1; i <= N; i++) {
        for(int j=1; j <= M; j++) {
            cumulative_sum[i][j] = square[i][j] + cumulative_sum[i - 1][j] + cumulative_sum[i][j - 1] - cumulative_sum[i - 1][j - 1];
        }
    }

    int ans = INT32_MIN;
    // i: 첫 번째 가로줄 j: 두 번째 가로줄 k: 첫 번째 세로줄 l: 두 번째 세로줄
    for(int i=1; i <= N; i++) {
        for(int j=i + 1; j <= N; j++) {
            for(int k=1; k <= M; k++) {
                for(int l=k + 1; l <= M; l++) {
                    int sum = 0;

                    // 각 길을 더하기
                    sum += get_area_sum(cumulative_sum, i, 1, i, M);
                    sum += get_area_sum(cumulative_sum, j, 1, j, M);
                    sum += get_area_sum(cumulative_sum, 1, k, N, k);
                    sum += get_area_sum(cumulative_sum, 1, l, N, l);

                    // 길끼리 겹치는 부분 빼기
                    sum -= square[i][k];
                    sum -= square[i][l];
                    sum -= square[j][k];
                    sum -= square[j][l];

                    // 길로 둘러쌓인 녹지의 넓이 더하기
                    if(j - i > 1 && l - k > 1) {
                        sum += (j - i - 1) * (l - k - 1);
                    }
                    ans = max(ans, sum);
                }
            }
        }
    }
    cout << ans << '\n';
}