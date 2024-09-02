#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    cout << N / 100 * 78 << ' ';
    cout << N / 10 * 2 / 100 * 78 + N / 10 * 8<< '\n';
}