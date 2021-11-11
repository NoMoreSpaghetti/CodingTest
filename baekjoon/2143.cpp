#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, n, m;
int A[1000], B[1000];
vector<int> v_A, v_B;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sum = 0;

    cin >> T >> n;
    for(int i=0; i < n; i++) {
        cin >> A[i];
        sum += A[i];
        v_A.push_back(sum);
    }

    sum = 0;
    cin >> m;
    for(int i=0; i < m; i++) {
        cin >> B[i];
        sum += B[i];
        v_B.push_back(sum);
    }

    int p_s = 0;
    for(int i=1; i < n; i++) {
        for(int j=i; j < n; j++) {
            v_A.push_back(v_A[p_s + j] - A[i - 1]);
        }
        p_s += (n - i);
    }

    p_s = 0;
    for(int i=1; i < m; i++) {
        for(int j=i; j < m; j++) {
            v_B.push_back(v_B[p_s + j] - B[i - 1]);
        }
        p_s += (m - i);
    }

    sort(v_A.begin(), v_A.end());
    sort(v_B.begin(), v_B.end());

    int prev_a = 1000000001;
    long long upper_bound = -1, lower_bound = -1;
    long long ans = 0;
    int left = 0, right = v_B.size() - 1;
    int prev_right = v_B.size() - 1;

    for(int i=0; i < v_A.size(); i++) {
        if(v_A[i] == prev_a && upper_bound != -1 && lower_bound != -1) {
            ans += upper_bound - lower_bound + 1;
            continue;
        }

        int remain_t = T - v_A[i];
        left = 0;
        right = prev_right;
        upper_bound = -1, lower_bound = -1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(v_B[mid] <= remain_t) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if(v_B[right] == remain_t) {
            upper_bound = right;
        }

        left = 0;
        right = upper_bound;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(v_B[mid] >= remain_t) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if(v_B[left] == remain_t) {
            lower_bound = left;
            prev_right = left;
        }

        if(upper_bound != -1 && lower_bound != -1) {
            ans += upper_bound - lower_bound + 1;
        }
        prev_a = v_A[i];
    }

    cout << ans << '\n';
}