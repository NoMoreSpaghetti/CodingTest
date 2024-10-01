#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N, 0));
    vector<vector<int>> B(N, vector<int>(N, 0));

    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            cin >> B[i][j];
        }
    }

    int ans = 0;
    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            int C = 0;
            for(int k=0; k < N; k++) {
                C |= A[i][k] & B[k][j];
            }
            if(C) {
                ans++;
            }
        }
    }

    cout << ans << '\n';
}