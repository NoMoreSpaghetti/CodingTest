#include <iostream>
using namespace std;

int my_pow(int x, int n) {
    int val = 1;
    while(n) {
        if(n & 1) {
            val *= x;
        }
        x *= x;
        n >>= 1;
    }
    return val;
}

int main() {
    int N;
    cin >> N;

    int len = 1;
    int size = 10;
    int num_of_nums = 10;

    while(N - size > 0) {
        len++;
        num_of_nums = 9 * my_pow(10, len - 1) * len;
        size += num_of_nums;
    }
    size -= num_of_nums;
    N -= size;

    int base_num = my_pow(10, len - 1);
    if(base_num == 1) {
        base_num = 0;
    }

    int full_number = N / len + base_num;
    int index_of_number = N % len;

    cout << to_string(full_number)[index_of_number] << '\n';
}