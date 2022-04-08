#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    bool ary[1001] = {0};
    ary[1] = true;
    ary[2] = false;
    ary[3] = true;
    ary[4] = true;

    for(int i=5; i <= N; i++) {
        ary[i] = !(ary[i - 1] && ary[i - 3] && ary[i - 4]);
    }

    if(ary[N]) {
        cout << "SK" << '\n';
    } else {
        cout << "CY" << '\n';
    }
}