#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    stack<char> ops;

    for(int i=0; i < s.length(); i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') {
            cout << s[i];
        } else if(s[i] == ')') {
            while(ops.top() != '(') {
                cout << ops.top();
                ops.pop();
            }
            ops.pop();
        } else if(s[i] == '(') {
            ops.push(s[i]);
        } else if(s[i] == '*' || s[i] == '/') {
            if(!ops.empty() && (ops.top() == '*' || ops.top() == '/')) {
                cout << ops.top();
                ops.pop();
            }
            ops.push(s[i]);
        } else {
            while(!ops.empty()) {
                char op = ops.top();
                if(op == '(') {
                    break;
                }
                ops.pop();
                cout << op;
            }
            ops.push(s[i]);
        }
    }

    while(!ops.empty()) {
        cout << ops.top();
        ops.pop();
    }

    cout << '\n';
}