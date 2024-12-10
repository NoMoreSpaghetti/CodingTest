#include <iostream>
#include <vector>
using namespace std;

int MAX_NUM = 246913;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<bool> prime(MAX_NUM, true);
    vector<int> cumulative_sum(MAX_NUM, 0);

    prime[0] = false;
    prime[1] = false;

    for(int i=2; i * i < MAX_NUM; i++) {
        if(!prime[i]) continue;
        for(int j=i * i; j < MAX_NUM; j += i) {
            prime[j] = false;
        }
    }

    for(int i=1; i < MAX_NUM; i++) {
        cumulative_sum[i] = cumulative_sum[i - 1];
        if(prime[i]) cumulative_sum[i]++;
    }

    while(n != 0) {
        cout << cumulative_sum[n * 2] - cumulative_sum[n] << '\n';
        cin >> n;
    }
}