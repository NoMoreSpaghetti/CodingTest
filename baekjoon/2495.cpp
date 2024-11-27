#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string num_s;

    for(int i=0; i < 3; i++) {
        cin >> num_s;
        int max_val = 0;
        int cnt = 1;
        for(int j=1; j < 8; j++) {
            if(num_s[j] == num_s[j - 1]) {
                cnt++;
            } else {
                max_val = max(max_val, cnt);
                cnt = 1;
            }
        }
        max_val = max(max_val, cnt);
        cout << max_val << '\n';
    }
}