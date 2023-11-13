#include <iostream>
#include <vector>
using namespace std;

int N;
int N_half;
int min_score_diff = 10000000;
vector<vector<int>> abilities;
vector<int> A;
vector<int> B;

void dfs(int idx) {
    if(idx == N) {
        int A_score = 0;
        int B_score = 0;
        for(int i=0; i < N_half; i++) {
            for(int j=i + 1; j < N_half; j++) {
                A_score += abilities[A[i]][A[j]];
                A_score += abilities[A[j]][A[i]];
                B_score += abilities[B[i]][B[j]];
                B_score += abilities[B[j]][B[i]];
            }
        }
        min_score_diff = min(min_score_diff, abs(A_score - B_score));

    } else {
        if(A.size() < N_half) {
            A.push_back(idx);
            dfs(idx + 1);
            A.pop_back();
        }
        if(B.size() < N_half) {
            B.push_back(idx);
            dfs(idx + 1);
            B.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    N_half = N / 2;

    abilities = vector<vector<int>>(N, vector<int>(N, 0));
    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            cin >> abilities[i][j];
        }
    }

    dfs(0);

    cout << min_score_diff << '\n';
}