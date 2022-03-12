#include <iostream>
using namespace std;

long long N;
long long nums[6];
int opposite_position[6] = {5, 4, 3, 2, 1, 0};

long long calc_min_sum_of_2_nums(long long ary[]) {
    long long min_sum = 100;
    for(int i=0; i < 5; i++) {
        for(int j=i + 1; j < 6; j++) {
            if(opposite_position[i] == j) {
                continue;
            }
            long long sum = ary[i] + ary[j];
            min_sum = min(min_sum, sum);
        }
    }

    return min_sum;
}

long long calc_min_sum_of_3_nums(long long ary[]) {
    long long min_sum = 150;
    for(int i=0; i < 4; i++) {
        for(int j=i + 1; j < 5; j++) {
            if(opposite_position[i] == j) {
                continue;
            }
            for(int k=j + 1; k < 6; k++) {
                if(opposite_position[j] == k || opposite_position[i] == k) {
                    continue;
                }

                long long sum = ary[i] + ary[j] + ary[k];
                min_sum = min(min_sum, sum);
            }
        }
    }

    return min_sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    

    cin >> N;
    for(int i=0; i < 6; i++) {
        cin >> nums[i];
    }

    long long ans = 0;

    if(N == 1) {
        long long sum = nums[0];
        long long max_num = nums[0];
        for(int i=1; i < 6; i++) {
            sum += nums[i];
            max_num = max(max_num, nums[i]);
        }
        
        ans = sum - max_num;
    } else {
        long long min_1_num = nums[0];
        for(int i=1; i < 6; i++) {
            min_1_num = min(min_1_num, nums[i]);
        }
        long long min_2_num = calc_min_sum_of_2_nums(nums);
        long long min_3_num = calc_min_sum_of_3_nums(nums);

        long long num_center = (N - 2) * (N - 2);
        long long sum_of_3_num = min_3_num * 4;
        long long sum_of_2_num = min_2_num * ((N - 1) * 4 + (N - 2) * 4);
        long long sum_of_1_num = min_1_num * (num_center + (num_center + (N - 2)) * 4);
        ans = sum_of_3_num + sum_of_2_num + sum_of_1_num;
    }
    cout << ans << '\n';
}