#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 0;
    vector<bool> is_self_num(10101, true);

    while(n <= 9973) {
        int result_num = n + ((n / 10) % 10) + ((n / 100) % 10) + (n / 1000);
        for(int i=0; i < 20; i += 2) {
            is_self_num[result_num + i] = false;
        }
        n += 10;
    }

    n = 1;
    while(n <= 10000) {
        if(is_self_num[n]) {
            cout << n << '\n';
        }
        n++;
    }
}