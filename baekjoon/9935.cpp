#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s, bomb;
    cin >> s >> bomb;

    stack<char> my_stack;
    int bomb_len = bomb.length();
    int match_char_idx = bomb_len - 1;

    for(int i=s.length()-1; i >= 0; i--) {
        char c = s[i];
        if(c == bomb[match_char_idx]) {
            match_char_idx--;
            if(match_char_idx == -1) {
                for(int j=1; j < bomb_len; j++) {
                    my_stack.pop();
                }
                for(int j=0; j < bomb_len-1; j++) {
                    if(my_stack.empty()) {
                        break;
                    }
                    s[i++] = my_stack.top();
                    my_stack.pop();
                }
            } else {
                my_stack.push(c);
            }
        } else {
            if(match_char_idx != bomb_len - 1) {
                i++;
            } else {
                my_stack.push(c);
            }
            match_char_idx = bomb_len - 1;
        }
    }

    if(my_stack.empty()) {
        cout << "FRULA" << '\n';
    } else {
        string ans;
        while(!my_stack.empty()) {
            ans += my_stack.top();
            my_stack.pop();
        }
        cout << ans << '\n';
    }
}