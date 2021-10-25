#include <iostream>
using namespace std;

long long binary_search(int* ary, int N, int M, int high) {
    long long left = 1;
    long long right = (long long)high * M;
    long long mid;
    long long num_b = 0;
    while(left <= right) {
        num_b = 0;
        mid = (right + left) / 2;
        
        for(int i=0; i < N; i++) {
            num_b += mid / (long long)ary[i];
        }

        if(num_b >= M) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    int *A = new int[N];
    int high = 0;
    
    for(int i=0; i < N; i++) {
        cin >> A[i];
        if(A[i] > high) {
            high = A[i];
        }
    }

    cout << binary_search(A, N, M, high) << '\n';

    delete[] A;
}