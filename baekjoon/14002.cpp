#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int N;
vector<int> dp;
vector<int> vec;
vector<int> index;

int lis() {
    int cur_idx = 0;
    dp[0] = vec[0];
    index[0] = 0;

    for(int i=1; i < N; i++) {
        if(vec[i] > dp[cur_idx]) {
            dp[++cur_idx] = vec[i];
            index[i] = cur_idx;
        } else {
            auto iter = lower_bound(dp.begin(), dp.begin() + cur_idx, vec[i]);
            *iter = vec[i];
            index[i] = iter - dp.begin();
        }
    }
    return cur_idx + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    dp = vector<int>(N, 0);
    vec = vector<int>(N, 0);
    index = vector<int>(N, 0);
    for(int i=0; i < N; i++) {
        cin >> vec[i];
    }

    int len_lis = lis();
    cout << len_lis << '\n';

    int idx = len_lis - 1;
    stack<int> s;
    for(int i=N - 1; i >= 0; i--) {
        if(idx == index[i]) {
            s.push(vec[i]);
            idx--;
        }
    }

    while(!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
}