def calc(a, b, op):
    if op == "+":
        return a + b
    elif op == "-":
        return a - b
    elif op == "*":
        return a * b
    elif op == "/":
        return a // b


N = int(input())

nums = []
ops = []

num = int(input())
nums.append(num)
for i in range(N - 1):
    op = input()
    num = int(input())

    if op in ["/", "*"]:
        num = calc(nums[-1], num, op)
        nums.pop()
        nums.append(num)
    else:
        nums.append(num)
        ops.append(op)

for i in range(len(ops)):
    a = nums[i]
    b = nums[i + 1]
    op = ops[i]

    nums[i + 1] = calc(a, b, op)

print(nums[-1])


# #include <iostream>
# #include <stack>
# #include <cmath>
# using namespace std;

# int calc(int a, int b, char op) {
#     switch(op) {
#         case '+':
#             return a + b;
#         case '-':
#             return a - b;
#         case '*':
#             return a * b;
#         case '/':
#             return floor((double)a / b);
#     }
# }

# int main() {
#     ios_base::sync_with_stdio(false);
#     cin.tie(NULL);
#     cout.tie(NULL);

#     int N, num;
#     char op;
#     cin >> N;
#     stack<int> nums;
#     stack<char> ops;

#     cin >> num;
#     nums.push(num);
#     for(int i=0; i < N - 1; i++) {
#         cin >> op;
#         cin >> num;
#         if(op == '/' || op == '*') {
#             int prev = nums.top();
#             nums.pop();
#             nums.push(calc(prev, num, op));
#         } else {
#             nums.push(num);
#             ops.push(op);
#         }
#     }

#     while(!ops.empty()) {
#         int b = nums.top();
#         nums.pop();
#         int a = nums.top();
#         nums.pop();
#         char op = ops.top();
#         ops.pop();

#         nums.push(calc(a, b, op));
#     }

#     cout << nums.top() << '\n';
# }
