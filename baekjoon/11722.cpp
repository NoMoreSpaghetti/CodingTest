#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> ans;
vector<int> A;

int GetLISLen() {
    vector<int> result;

    result.push_back(A[0]);

    for(int i=1; i < N; i++) {
        if(A[i] < result.back()) {
            result.push_back(A[i]);
            continue;
        }

        auto it = lower_bound(result.begin(), result.end(), A[i], greater<int>());
        *it = A[i];
    }

    return result.size();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    A = vector<int>(N, 0);
    ans = vector<int>(N, -1);

    for(int i=0; i < N; i++) {
        cin >> A[i];
    }

    cout << GetLISLen() << '\n';
}