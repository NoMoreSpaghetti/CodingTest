#include <iostream>
#include <string.h>
using namespace std;

int N;
bool is_prime[4000001];

int main() {
    memset(is_prime, true, sizeof(is_prime));

    cin >> N;

    is_prime[0] = is_prime[1] = false;

    for(int i=2; i <= N; i++) {
        if(is_prime[i] == false) {
            continue;
        } else {
            for(int j=i * 2; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int left = 2, right = 2, sum = 2;
    int ans = 0;

    if(is_prime[N] == true) {
        ans++;
    }

    while(right < N) {
        if(sum < N) {
            right++;
            while(right < N && is_prime[right] == false) {
                right++;
            }
            sum += right;
        } else if(sum > N) {
            sum -= left;
            left++;
            while(is_prime[left] == false) {
                left++;
            }
            // left == right이고 sum > N이면 left > right. right < N이므로 발생하지 않음
        } else {
            ans++;
            sum -= left;
            left++;
            while(is_prime[left] == false) {
                left++;
            }
            right++;
            while(right < N && is_prime[right] == false) {
                right++;
            }
            sum += right;
        }
    }

    cout << ans << '\n';
}