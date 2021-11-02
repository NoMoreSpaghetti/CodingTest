#include <iostream>
#include <queue>
using namespace std;

int N;
long long x[10001];
long long y[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int n=0; n < N; n++) {
        cin >> x[n] >> y[n];
    }

    x[N] = x[0];
    y[N] = y[0];
    long long result = 0;
    for(int n=0; n < N; n++) {
        result += x[n] * y[n+1];
        result -= y[n] * x[n+1];
    }
    result = abs(result);

    cout << result / 2;

    if((result & 1) == 1) {
        cout << ".5" << '\n';
    } else {
        cout << ".0" << '\n';
    }
}