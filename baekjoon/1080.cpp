#include <iostream>
#include <vector>
using namespace std;

void convert(string A[], int y, int x) {
    for(int i=0; i < 3; i++) {
        for(int j=0; j < 3; j++) {
            A[i + y][j + x] = (A[i + y][j + x] == '0') ? '1' : '0';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, answer = 0;
    string A[51], B[51];
    cin >> N >> M;
    
    for(int i=0; i < N; i++) {
        cin >> A[i];
    }

    for(int i=0; i < N; i++) {
        cin >> B[i];
    }

    for(int i=1; i < N - 1; i++) {
        for(int j=1; j < M - 1; j++) {
            if(A[i - 1][j - 1] != B[i - 1][j - 1]) {
                convert(A, i - 1, j - 1);
                answer++;
            }
        }
        for(int j=M - 2; j < M; j++) {
            if(j >= 0) {
                if(A[i - 1][j] != B[i - 1][j]) {
                    answer = -1;
                    break;
                }
            }
        }
        if(answer == -1) {
            break;
        }
    }

    for(int i=N - 2; i < N; i++) {
        if(i >= 0) {
            for(int j=0; j < M; j++) {
                if(A[i][j] != B[i][j]) {
                    answer = -1;
                    break;
                }
            }
            if(answer == -1) {
                break;
            }
        }
    }

    cout << answer << '\n';
}