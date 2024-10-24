#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> vecs;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    vecs = vector<vector<int>>(4, vector<int>(N, 0));
    vector<int> CD;

    for(int i=0; i < N; i++) {
        for(int j=0; j < 4; j++) {
            cin >> vecs[j][i];
        }
    }

    for(int i=0; i < 2; i++) {
        sort(vecs[i].begin(), vecs[i].end());
    }

    // C와 D를 더한 값을 미리 모두 저장해 놓기
    // O(N ^ 2)
    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            CD.push_back(vecs[2][i] + vecs[3][j]);
        }
    }

    sort(CD.begin(), CD.end());

    int sum = 0;
    long long ans = 0;
    for(int i=0; i < N; i++) {
        sum += vecs[0][i];

        long long num_combinations = 0;

        for(int j=0; j < N; j++) {
            sum += vecs[1][j];

            int cur = 0;

            auto eq_range = equal_range(CD.begin(), CD.end(), -sum);
            long long num = eq_range.second - eq_range.first;
            num_combinations += num;

            sum -= vecs[1][j];

            while(j + 1 < N && vecs[1][j + 1] == vecs[1][j]) {
                num_combinations += num;
                j++;
            }
        }

        sum -= vecs[0][i];

        // 다음 값이 같은 동안 현재 값에서 얻은 조합 수를 계속 더하기
        ans += num_combinations;
        while(i + 1 < N && vecs[0][i + 1] == vecs[0][i]) {
            ans += num_combinations;
            i++;
        }
    }

    cout << ans << '\n';
}