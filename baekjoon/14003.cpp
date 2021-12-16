#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N;
int ary[1000000];
int dp[1000000];
vector<int> v;

int binary_search(int left, int right, int val) {
    int mid;
    while(left < right) {
        mid = (left + right) / 2;
        if(v[mid] >= val) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return right;
}

void get_LIS() {
    v.push_back(ary[0]);
    for(int i=1; i < N; i++) {
        if(ary[i] > *(v.end() - 1)) {
            dp[i] = v.size();
            v.push_back(ary[i]);
        } else {
            int idx = binary_search(0, v.size(), ary[i]);
            dp[i] = idx;
            v[idx] = ary[i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i=0; i < N; i++) {
        cin >> ary[i];
    }

    get_LIS();

    stack<int> print_s;

    for(int i=N - 1; i >= 0; i--) {
        if(dp[i] == v.size() - 1) {
            print_s.push(ary[i]);
            v.erase(v.end() - 1);
        }
    }

    cout << print_s.size() << '\n';
    while(!print_s.empty()) {
        cout << print_s.top() << ' ';
        print_s.pop();
    }
}