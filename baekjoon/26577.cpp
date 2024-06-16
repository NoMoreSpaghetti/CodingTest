#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
using namespace std;

int precedence(char op) {
    if(op == '*' || op == '/' || op == '%') {
        return 2;
    } else if(op == '+' || op == '-') {
        return 1;
    } else {
        return 0;
    }
}

int calc(int num1, int num2, char op) {
    switch(op) {
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        case '%':
            return num1 % num2;
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
    }
}

int evaluate_str(string equation) {
    stack<char> ops;
    stack<int> nums;
    istringstream ss(equation);

    int num;
    char op;
    while(ss >> num) {
        nums.push(num);
        if(!ss.eof()) {
            ss >> op;
            while(!ops.empty() && precedence(op) <= precedence(ops.top())) {
                char prev_op = ops.top();
                ops.pop();
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                nums.push(calc(num2, num1, prev_op));
            }
            ops.push(op);
        }
    }

    while(!ops.empty()) {
        char op = ops.top();
        ops.pop();
        int num1 = nums.top();
        nums.pop();
        int num2 = nums.top();
        nums.pop();
        nums.push(calc(num2, num1, op));
    }
    return nums.top();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string str;
    cin >> n;
    cin.ignore();
    
    while(n--) {
        getline(cin, str);

        cout << evaluate_str(str) << '\n';
    }
}