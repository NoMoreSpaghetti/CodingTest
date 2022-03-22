#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    cin >> K;

    int N = 1;
    while(K > N) {
        N *= 2;
    }
    cout << N << ' ';

    int num = -1;
    while(K != 0) {
        if(K >= N) {
            K -= N;
        }
        if(K >= N) {
            K -= N;
        }
        N >>= 1;
        num++;
    }

    cout << num << '\n';
}