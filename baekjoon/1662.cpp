#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string S;
    cin >> S;

    stack<int> num_s;
    stack<int> mul_s;
    stack<char> op_s;

    int prefix_len = 0;
    for(int i=0; i < S.length(); i++) {
        if(S[i] == '(') {
            op_s.push(S[i]);
            mul_s.push(S[i - 1] - '0');
            num_s.push(prefix_len - 1);
            prefix_len = 0;

        } else if(S[i] == ')') {
            op_s.pop();

            int num = 0;

            if(!num_s.empty()) {
                num = num_s.top();
                num_s.pop();
            }
            num += prefix_len * mul_s.top();

            mul_s.pop();
            prefix_len = num;
        } else {
            prefix_len++;
        }
    }

    cout << prefix_len << '\n';
}