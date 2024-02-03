#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int binary_search(const vector<int>& dp, int left, int right, int val) {
    int mid;
    while(left < right) {
        mid = (left + right) / 2;
        if(dp[mid] < val) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return right;
}


int lis() {
    vector<int> dp(N, 0);
    int ans_idx = 0;
    dp[0] = pq.top().second;
    pq.pop();

    for(int i=1; i < N; i++) {
        int val = pq.top().second;
        pq.pop();

        if(dp[ans_idx] < val) {
            dp[++ans_idx] = val;
        } else {
            int idx = binary_search(dp, 0, ans_idx, val);
            dp[idx] = val;
        }
    }
    return ans_idx + 1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int A, B;
    

    for(int i=0; i < N; i++) {
        cin >> A >> B;
        pq.push({A, B});
    }

    cout << N - lis() << '\n';
}