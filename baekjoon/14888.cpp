#include <iostream>
#include <vector>
#include <tuple>
#include <stack>
using namespace std;

int N;

int calc_four_basic_ops(int a, int b, int op_idx) {
    switch(op_idx) {
        case 0:
            return a + b;
        case 1:
            return a - b;
        case 2:
            return a * b;
        case 3:
            return a / b;
    }
}

void solution(vector<int>& nums, vector<int>& num_ops, int& max_val, int& min_val) {
    max_val = -1000000000;
    min_val = 1000000000;

    stack<pair<pair<int, int>, vector<int>>> s;
    s.push({{nums[0], 1}, num_ops});

    while(!s.empty()) {
        int cur_val = s.top().first.first;
        int next_num_idx = s.top().first.second;
        vector<int> cur_num_ops = s.top().second;
        s.pop();

        if(next_num_idx == N) {
            max_val = max(max_val, cur_val);
            min_val = min(min_val, cur_val);
        } else {
            for(int i=0; i < 4; i++) {
                if(cur_num_ops[i] > 0) {
                    vector<int> next_num_ops(cur_num_ops);
                    next_num_ops[i]--;
                    int next_val = calc_four_basic_ops(cur_val, nums[next_num_idx], i);
                    s.push({{next_val, next_num_idx + 1}, next_num_ops});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    vector<int> nums(N, 0);
    vector<int> num_ops(4, 0);

    for(int i=0; i < N; i++) {
        cin >> nums[i];
    }

    for(int i=0; i < 4; i++) {
        cin >> num_ops[i];
    }

    int max_val, min_val;
    solution(nums, num_ops, max_val, min_val);

    cout << max_val << '\n' << min_val << '\n';
}