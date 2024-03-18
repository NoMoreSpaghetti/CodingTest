#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int k;
long long max_val = 0;
long long min_val = 9999999999;
vector<char> signs;

bool compare_two_nums(const char& c, const long long& num1, const long long& num2) {
    if(c == '<') {
        return num1 < num2;
    } else {
        return num1 > num2;
    }
}

void recursive(int cur_pos, int remain_bit, long long num) {
    if(cur_pos == k) {
        max_val = max(max_val, num);
        min_val = min(min_val, num);
        return;
    }

    for(long long i=0; i <= 9; i++) {
        if(compare_two_nums(signs[cur_pos], num % 10, i)) {
            int cur_bit = (1 << i);
            if(!(remain_bit & cur_bit)) {
                recursive(cur_pos + 1, remain_bit | cur_bit, num * 10 + i);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    signs = vector<char>(k, ' ');
    for(int i=0; i < k; i++) {
        cin >> signs[i];
    }
    for(long long i=0; i <= 9; i++) {
        recursive(0, (1 << i), i);
    }

    cout << setfill('0') << setw(k + 1) << max_val << '\n';
    cout << setfill('0') << setw(k + 1) << min_val << '\n';
}