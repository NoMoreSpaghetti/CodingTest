#include <iostream>
#include <vector>
using namespace std;

vector<long long> fib;

long long get_fib(int n) {
    if(fib[n] != -1) {
        return fib[n];
    }

    return fib[n] = get_fib(n - 1) + get_fib(n - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    fib = vector<long long>(n + 1, -1);
    fib[0] = 0;
    fib[1] = 1;
    
    cout << get_fib(n) << '\n';
}