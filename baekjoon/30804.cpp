#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> fruits(N, 0);
    vector<int> nums(10, 0);
    
    for(int i=0; i < N; i++) {
        cin >> fruits[i];
    }

    int answer = 1;
    int left_idx = 0;
    int right_idx = 0;
    int kinds_of_fruits = 1;
    nums[fruits[left_idx]] = 1;

    while(right_idx < N - 1) {
        // 오른쪽 포인터 이동
        right_idx++;
        if(nums[fruits[right_idx]] == 0) {
            kinds_of_fruits++;
        }
        nums[fruits[right_idx]]++;

        // 왼쪽 포인터 이동
        while(kinds_of_fruits > 2) {
            nums[fruits[left_idx]]--;
            if(nums[fruits[left_idx]] == 0) {
                kinds_of_fruits--;
            }

            left_idx++;
        }
        answer = max(answer, right_idx - left_idx + 1);
    }

    cout << answer << '\n';
}