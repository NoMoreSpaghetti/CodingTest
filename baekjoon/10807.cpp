#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, inp;
    cin >> N;

    int nums[201] = {0};

    while(N--) {
        cin >> inp;
        nums[inp + 100]++;
    }

    cin >> inp;
    cout << nums[inp + 100] << '\n';
}