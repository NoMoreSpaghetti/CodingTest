#include <iostream>
#include <vector>
using namespace std;

int N, sum;
int temp;
vector<int> sums;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    sum = 0;
    sums = vector<int>(N, 0);

    for(int i=0; i < N; i++) {
        cin >> sums[i];
        sum += sums[i];
        if(i % 2 == 0) {
            temp += sums[i];
        } else {
            temp -= sums[i];
        }
    }
    temp -= sums[N - 1];

    for(int i=0; i < N; i++) {
        temp += sums[(i - 1 + N) % N];
        cout << (temp >> 1) << '\n';

        temp -= sums[i];

        temp = -temp;
    }
    
}