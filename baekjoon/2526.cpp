#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, P;
    cin >> N >> P;

    vector<int> vec(P + 1, 0);
    int num = N;
    int idx = 1;

    while(true) {
        num = num * N % P;
        if(vec[num] != 0) {
            break;
        }
        vec[num] = idx++;
    }

    cout << idx - vec[num] << '\n';
}