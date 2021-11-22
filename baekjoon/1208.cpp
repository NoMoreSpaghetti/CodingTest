#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, S;
int ary[40];
long long ans = 0;
vector<int> v1;
vector<int> v2;

void recursive(int cur, int right, int sum, vector<int> &v) {
    if(cur == right) {
        v.push_back(sum);
        return;
    }
    recursive(cur + 1, right, sum + ary[cur], v);
    recursive(cur + 1, right, sum, v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S;
    for(int i=0; i < N; i++) {
        cin >> ary[i];
    }

    recursive(0, N / 2, 0, v1);
    recursive(N / 2, N, 0, v2);

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    long long v1_i = 0;
    long long v2_i = v2.size() - 1;

    while(v1_i < v1.size() && v2_i >= 0) {
        long long sum = v1[v1_i] + v2[v2_i];
        if(sum == S) {
            long long n1 = 1;
            long long n2 = 1;
            v1_i++;
            v2_i--;
            while((v1_i) < v1.size() && v1[v1_i] == v1[v1_i - 1]) {
                v1_i++;
                n1++;
            }
            while((v2_i) >= 0 && v2[v2_i] == v2[v2_i + 1]) {
                v2_i--;
                n2++;
            }
            ans += n1 * n2;
        } else if(sum > S) {
            v2_i--;
        } else {
            v1_i++;
        }
    }

    if(S == 0) {
        ans--;
    }

    cout << ans << '\n';
}