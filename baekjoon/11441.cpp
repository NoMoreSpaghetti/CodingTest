#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> vec;
int M, i, j;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int temp;
    int sum = 0;
    vec.push_back(0);
    for(int k=0; k < N; k++) {
        cin >> temp;
        sum += temp;
        vec.push_back(sum);
    }

    cin >> M;
    for(int k=0; k < M; k++) {
        cin >> i >> j;
        cout << vec[j] - vec[i - 1] << '\n';
    }
}