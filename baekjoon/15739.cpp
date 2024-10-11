#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n, 0));
    vector<int> nums(n * n + 1, 0);
    int answer = true;

    for(int i=0; i < n; i++) {
        for(int j=0; j < n; j++) {
            cin >> matrix[i][j];
            if(nums[matrix[i][j]] > 0) {
                answer = false;
                break;
            }
            nums[matrix[i][j]]++;
        }
        if(!answer) {
            break;
        }
    }

    if(answer) {
        int sum = n * (n * n + 1) / 2;
        int sum1, sum2;

        // 가로, 세로 검사
        for(int i=0; i < n; i++) {
            sum1 = 0;
            sum2 = 0;
            for(int j=0; j < n; j++) {
                sum1 += matrix[i][j];
                sum2 += matrix[j][i];
            }

            if(sum1 != sum || sum2 != sum) {
                answer = false;
                break;
            }
        }

        sum1 = 0;
        sum2 = 0;
        for(int i=0; i < n; i++) {
            sum1 += matrix[i][i];
            sum2 += matrix[i][n - 1 - i];
        }

        if(sum1 != sum || sum2 != sum) {
            answer = false;
        }
    }

    cout << (answer ? "TRUE" : "FALSE") << '\n';
}