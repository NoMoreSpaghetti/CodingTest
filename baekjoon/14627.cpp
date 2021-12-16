#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long S;
long long C;
vector<long long> green_onions;

bool check_num_chicken_enough(long long cut_len) {
    long long num = 0;
    for(int i=0; i < green_onions.size(); i++) {
        num += green_onions[i] / cut_len;
    }
    if(num < C) {
        return false;
    } else {
        return true;
    }
}

long long binary_search() {
    long long left = 1;
    long long right = 1000000000;
    long long mid = (right + left) / 2;
    long long ans = 0;

    while(left <= right) {
        mid = (right + left) / 2;
        bool valid_len = check_num_chicken_enough(mid);
        if(valid_len) {
            ans = max(ans, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long inp;
    long long sum = 0;
    cin >> S >> C;
    for(int i=0; i < S; i++) {
        cin >> inp;
        green_onions.push_back(inp);
        sum += inp;
    }
    
    long long go_len = binary_search();
    cout << sum - (go_len * C) << '\n';
}