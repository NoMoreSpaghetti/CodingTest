#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int digit_nums = 9;
    int len = 0;
    int count = 1;
    while(N > 0) {
        N -= digit_nums;
        len += (digit_nums * count);
        digit_nums *= 10;
        count++;
    }
    digit_nums /= 10;
    count--;
    len -= (-N * count);

    cout << len << '\n';
}