#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N;
    vector<pair<int, int>> A(N, {0, 0});
    for(int i=0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = -i;
    }

    cin >> M;
    vector<pair<int, int>> B(M, {0, 0});
    for(int i=0; i < M; i++) {
        cin >> B[i].first;
        B[i].second = -i;
    }

    sort(A.begin(), A.end(), greater<pair<int, int>>());
    sort(B.begin(), B.end(), greater<pair<int, int>>());

    vector<int> lcs;
    int A_idx = 0, A_prev_idx = 1;
    int B_idx = 0, B_prev_idx = 1;
    while(A_idx < N && B_idx < M) {
        if(A[A_idx].first == B[B_idx].first && A[A_idx].second < A_prev_idx && B[B_idx].second < B_prev_idx) {
            lcs.push_back(A[A_idx].first);
            A_prev_idx = A[A_idx].second;
            B_prev_idx = B[B_idx].second;
            A_idx++;
            B_idx++;
        } else if(A[A_idx].first > B[B_idx].first) {
            A_idx++;
        } else if(A[A_idx].first < B[B_idx].first) {
            B_idx++;
        } else {
            if(A[A_idx].second > A_prev_idx) {
                A_idx++;
            } else {
                B_idx++;
            }
        }
    }

    cout << lcs.size() << '\n';
    for(const auto& element : lcs) {
        cout << element << ' ';
    }
}