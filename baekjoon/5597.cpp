#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int inp, students[31] = {0};
    for(int i=0; i < 28; i++) {
        cin >> inp;
        students[inp] = 1;
    }

    for(int i=1; i <= 30; i++) {
        if(!students[i]) {
            cout << i << '\n';
        }
    }
}