#include <iostream>
#include <cstdlib>
#define SWAP(type, a, b) do {type temp = a; a = b; b = temp;} while(0);
using namespace std;

int N;
long long solution[5000];
int ans_idx[3];

int partition(long long ary[], int left, int right) {
    long long p = ary[right];
    int low = left - 1;
    for(int high=left; high <= right; high++) {
        if(ary[high] < p) {
            low++;
            SWAP(long long, ary[low], ary[high]);
        }
    }
    SWAP(long long, ary[right], ary[low + 1]);

    return low + 1;
}

void quick_sort(long long ary[], int left, int right) {
    if(left < right) {
        int q = partition(ary, left, right);
        quick_sort(ary, left, q - 1);
        quick_sort(ary, q + 1, right);
    }
}

void get_three_solutions() {
    long long sum = 0;
    long long min_abs_sum = 3000000001;
    for(int mid=1; mid < N - 1; mid++) {
        long long before_sum = 3000000001;
        int left = mid - 1, right = mid + 1;
        while(left >= 0 && right < N) {
            sum = solution[mid] + solution[left] + solution[right];
            long long abs_sum = abs(sum);
            if(abs_sum < min_abs_sum) {
                min_abs_sum = abs_sum;
                ans_idx[0] = left;
                ans_idx[1] = mid;
                ans_idx[2] = right;
            }
            if(sum > 0) {
                // 합이 양수일 때
                left--;
            } else {
                // 합이 음수일 때
                right++;
            }
            before_sum = sum;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i=0; i < N; i++) {
        cin >> solution[i];
    }
    
    quick_sort(solution, 0, N - 1);
    get_three_solutions();

    for(int i=0; i < 3; i++) {
        cout << solution[ans_idx[i]] << ' ';
    }
    cout << '\n';
}