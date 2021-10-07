#include <iostream>
#include <cstring>
using namespace std;

int N;
int A[1001];
int B[1001];

int binary_search(int val, int max_len) {
    int start = 1;
    int end = max_len;
    int mid;
    while(start <= end) {
        mid = (start + end) / 2;
        if(val == B[mid]) {
            break;
        }
        else if(val < B[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return mid;
}

int get_length_of_LIS() {
    int max_len = 1;
    for(int n=2; n <= N; n++) {
        int idx = binary_search(A[n], max_len);
        if(A[n] > B[idx]) {
            B[idx+1] = A[n];
            if(idx == max_len) {
                max_len++;
            }
        }
        else if(A[n] < B[idx]) {
            B[idx] = A[n];
        }
    }

    return max_len;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int n=1; n <= N; n++) {
        cin >> A[n];
    }

    memset(B, -1, sizeof(B));
    A[0] = 0;
    B[0] = 0;
    B[1] = A[1];
    
    cout << get_length_of_LIS() << '\n';
}