#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M1, Y1, M2, Y2;
    double EIT = 0.0;

    cin >> N;
    cout << fixed;
    cout.precision(4);

    while(N--) {
        cin >> M1 >> Y1 >> M2 >> Y2;
        EIT = 0.0;
        if(Y2 > Y1) {
            EIT += 0.5;
            EIT += (Y2 - Y1 - 1);
            EIT += (M2 - 1) / 12.0;
        } else {
            EIT += 0.5 / (13 - M1) * (M2 - M1);
        }
        cout << EIT << '\n';
    }
}