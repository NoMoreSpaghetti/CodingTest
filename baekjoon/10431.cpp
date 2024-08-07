#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int P, T, inp;
    cin >> P;

    while(P--) {
        cin >> T;
        vector<int> students(20, 0);
        int ans = 0;

        for(int i=0; i < 20; i++) {
            cin >> inp;
            int j=0;
            for(; j < i; j++) {
                if(students[j] > inp) {
                    for(int k=i; k > j; k--) {
                        swap(students[k], students[k - 1]);
                    }
                    ans += i - j;
                    break;
                }
            }
            students[j] = inp;
        }

        cout << T << ' ' << ans << '\n';
    }
}