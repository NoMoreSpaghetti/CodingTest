#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> ans(N, 0);

    int i = N;
    int left = 0;
    int right = N - 1;

    while(left < right) {
        ans[right--] = i--;
        ans[left++] = i--;
        if(left < right) {
            ans[left++] = i--;
            ans[right--] = i--;
        }
    }
    if(left == right) {
        ans[left] = i;
    }

    for(const auto& val: ans) {
        cout << val << ' ';
    }
}