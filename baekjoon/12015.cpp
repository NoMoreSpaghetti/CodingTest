// 참고: https://sihyungyou.github.io/baekjoon-12015/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, x;
    int max_len = 0;
    vector<int> v;
    v.push_back(0);

    cin >> N;
    for(int n=0; n < N; n++) {
        cin >> x;
        if(x > v.back()) {
            v.push_back(x);
            max_len++;
        } else {
            vector<int>::iterator it = lower_bound(v.begin(), v.end(), x);
            *it = x;
        }
    }

    cout << max_len << '\n';
}