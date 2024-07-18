#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> butters(N, vector<int>(2, 0));
    for(int i=0; i < N; i++) {
        cin >> butters[i][0] >> butters[i][1];
    }

    sort(butters.begin(), butters.end());

    int ans = INT32_MAX;
    for(int i=1; i < N; i++) {
        int x_interval = butters[i][0] - butters[i - 1][0] - 1;
        int melted_butter_length = (butters[i][1] >> 1) + (butters[i - 1][1] >> 1);

        if(melted_butter_length > x_interval) {
            int left = 0;
            int right = max(butters[i][1] >> 1, butters[i - 1][1] >> 1);
            int max_t = 0;
            while(left <= right) {
                int mid = (left + right) >> 1;

                melted_butter_length = min(butters[i][1] >> 1, mid) + min(butters[i - 1][1] >> 1, mid);

                if(melted_butter_length == x_interval) {
                    max_t = mid;
                    break;
                } else if(melted_butter_length > x_interval) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                    max_t = max(max_t, mid);
                }
            }

            ans = min(ans, max_t);
        }
    }

    if(ans == INT32_MAX) {
        cout << "forever" << '\n';
    } else {
        cout << ans << '\n';
    }
}