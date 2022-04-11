#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long S;
    cin >> S;

    long long i = 1;
    long long sum = 1;
    while(sum <= S) {
        i++;
        sum += i;
    }

    cout << i - 1 << '\n';
}