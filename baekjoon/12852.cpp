#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int N;
int dp[1000001] = {0};

int bfs() {
    int new_n, ans;
    queue<pair<int, int>> q;
    q.push(make_pair(N, 0));

    while(!q.empty()) {
        int cur = q.front().first;
        int len = q.front().second;
        q.pop();

        if(cur == 0) {
            continue;
        } else if(cur == 1) {
            ans = len;
            break;
        }
        
        if(cur % 3 == 0) {
            new_n = cur / 3;
            if(dp[new_n] == 0) {
                q.push(make_pair(new_n, len + 1));
                dp[new_n] = cur;
            }
        }
        // 2로 나눈 나머지
        if((cur & 1) == 0) {
            new_n = cur >> 1;
            if(dp[new_n] == 0) {
                q.push(make_pair(new_n, len + 1));
                dp[new_n] = cur;
            }
        }

        new_n = cur - 1;
        if(new_n > 0 && dp[new_n] == 0) {
            q.push(make_pair(new_n, len + 1));
            dp[new_n] = cur;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    cout << bfs() << '\n';

    stack<int> s;
    s.push(1);
    int before_n = dp[1];

    while(before_n != 0) {
        s.push(before_n);
        if(before_n == N) {
            break;
        }
        before_n = dp[before_n];
    }

    while(!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
}