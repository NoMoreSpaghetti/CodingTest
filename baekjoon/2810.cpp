#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string seats;
    cin >> N >> seats;

    int num_LL = 0;
    for(int i=0; i < N; i++) {
        if(seats[i] == 'L') {
            num_LL++;
            i++;
        }
    }

    cout << min(N, N + 1 - num_LL) << '\n';
}