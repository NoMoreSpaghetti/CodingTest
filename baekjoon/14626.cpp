#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char ISBN[13];
    int weight[] = {1, 3};
    int check_num = 0;
    int missed_num_idx = 0;
    for(int i=0; i < 13; i++) {
        cin >> ISBN[i];
    }

    for(int i=0; i < 12; i++) {
        if(ISBN[i] == '*') {
            missed_num_idx = i;
            continue;
        } else {
            check_num += (ISBN[i] - '0') * weight[i % 2];
        }
    }

    check_num %= 10;
    int missed_num = (20 - check_num - (ISBN[12] - '0')) % 10;
    if(weight[missed_num_idx % 2] == 1) {
        cout << missed_num << '\n';
    } else {
        if(missed_num % 3 == 0) {
            cout << missed_num << '\n';
        } else {
            cout << ((3 - (missed_num % 3)) * 10 + missed_num) / 3 << '\n';
        }
    }
}