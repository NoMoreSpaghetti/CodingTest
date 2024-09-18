#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, A, B;
    cin >> N >> A >> B;

    // 지하철을 탈 수 있는 경우
    if(N <= B) {
        if(B < A) {
            cout << "Subway" << '\n';
            return 0;
        } else if(B == A) {
            cout << "Anything" << '\n';
            return 0;
        }
    }

    cout << "Bus" << '\n';
}