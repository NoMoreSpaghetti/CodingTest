#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
vector<char> alps;

bool vowels[26] = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};

void recursive_func(string passwd, int num_vowels, int idx) {
    if(passwd.length() == L) {
        if(num_vowels >= 1 && passwd.length() - num_vowels >= 2) {
            cout << passwd << '\n';
        }
    } else {
        if(idx < C) {
            if(vowels[alps[idx] - 'a']) {
                recursive_func(passwd + alps[idx], num_vowels + 1, idx + 1);
            } else {
                recursive_func(passwd + alps[idx], num_vowels, idx + 1);
            }
            recursive_func(passwd, num_vowels, idx + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char inp;
    cin >> L >> C;

    for(int c=0; c < C; c++) {
        cin >> inp;
        alps.push_back(inp);
    }

    sort(alps.begin(), alps.end());

    recursive_func("", 0, 0);
}