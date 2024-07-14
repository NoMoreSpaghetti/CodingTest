#include <iostream>
#include <vector>
using namespace std;

vector<long long> dp;

long long get_fib(int num) {
    if(dp[num] != 0) {
        return dp[num];
    }
    
    if(num % 2 == 0) {
        long long a = get_fib((num >> 1));
        long long b = get_fib((num >> 1) - 1);
        long long c = get_fib((num >> 1) + 1);
    } else {
        long long a = get_fib(((num + 1) >> 1));
        long long b = get_fib(((num + 1) >> 1) - 1);
        return dp[num] = a * a + b * b;
    }
    return dp[num] = get_fib(num - 1) + get_fib(num - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    dp = vector<long long>(N + 2, 0);
    dp[1] = 1;
    dp[2] = 1;

    cout << get_fib(N + 1) * 2 + get_fib(N) * 2 << '\n';
}