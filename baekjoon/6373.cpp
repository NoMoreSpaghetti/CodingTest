#include <iostream>
#include <vector>
using namespace std;

bool check_cycle(string s1, string s2) {
    for(int i=0; i < s1.length(); i++) {
        int idx = 0;
        while(idx < s1.length() && s1[idx] == s2[(idx + i) % s1.length()]) {
            idx++;
        }
        if(idx == s1.length()) {
            return true;
        }
    }
    return false;
}

bool solution(string str_num) {
    for(int i = 1; i < str_num.size() + 1; i++) {
        string result = str_num;
        int carry = 0;
        for(int j=str_num.size() - 1; j >= 0; j--) {
            int num = (str_num[j] - '0') * i + carry;
            carry = num / 10;
            result[j] = num % 10 + '0';
        }
        if(carry > 0 || !check_cycle(str_num, result)) {
            return false;
        }
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    string inp;
    while(getline(cin, inp)) {
        if(inp == "\0") {
            break;
        }
        
        if(solution(inp)) {
            cout << inp << " is cyclic\n";
        } else {
            cout << inp << " is not cyclic\n";
        }
    }
}