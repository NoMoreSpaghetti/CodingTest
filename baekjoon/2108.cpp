#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> vec;
    int N, temp, sum = 0;
    long long avg, mid, mode, range;
    cin >> N;
    for(int i=0; i < N; i++) {
        cin >> temp;
        vec.push_back(temp);
        sum += temp;
    }

    sort(vec.begin(), vec.end(), greater<int>());

    // 최빈값 계산
    int cnt = 1;
    int max_cnt = 0;
    mode = vec[0];
    int prev_mode = mode;
    int prev = vec[0];
    for(int i=1; i < vec.size(); i++) {
        if(prev == vec[i]) {
            cnt++;
        } else {
            if(max_cnt < cnt) {
                max_cnt = cnt;
                mode = prev;
                prev_mode = prev;
            } else if(max_cnt == cnt) {
                prev_mode = mode;
                mode = prev;
            }
            cnt = 1;
        }
        prev = vec[i];
    }
    if(max_cnt < cnt) {
        max_cnt = cnt;
        mode = prev;
        prev_mode = prev;
    } else if(max_cnt == cnt) {
        prev_mode = mode;
        mode = prev;
    }

    avg = round((double)sum / vec.size());
    mid = vec[vec.size() / 2];
    mode = prev_mode;
    range = vec.front() - vec.back();

    cout << avg << '\n';
    cout << mid << '\n';
    cout << mode << '\n';
    cout << range << '\n';
}