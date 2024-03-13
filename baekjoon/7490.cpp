#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int T, N;

void dfs(int N) {
    stack<pair<string, int>> s;
    s.push({"1", 1});
    while(!s.empty()) {
        string cur_s = s.top().first;
        int cur_num = s.top().second;
        s.pop();

        if(cur_num == N) {
            int sum = 0;
            int num = 1;
            for(int i=1; i < cur_s.length(); i += 2) {
                switch(cur_s[i]) {
                    case '+':
                        sum += num;
                        num = cur_s[i + 1] - '0';
                        break;
                    case '-':
                        sum += num;
                        num = -(cur_s[i + 1] - '0');
                        break;
                    case ' ':
                        num *= 10;
                        if(num < 0) {
                            num -= cur_s[i + 1] - '0';
                        } else {
                            num += cur_s[i + 1] - '0';
                        }
                        break;
                }
            }

            sum += num;
            if(sum == 0) {
                cout << cur_s << '\n';
            }

        } else {
            cur_num++;
            string num_str = to_string(cur_num);
            s.push({cur_s + "-" + num_str, cur_num});
            s.push({cur_s + "+" + num_str, cur_num});
            s.push({cur_s + " " + num_str, cur_num});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while(T--) {
        cin >> N;
        dfs(N);
        cout << '\n';
    }
}