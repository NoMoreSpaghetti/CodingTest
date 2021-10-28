#include <iostream>
#define SWAP(type, a, b) do{type temp = a; a = b; b = temp;} while(0);
using namespace std;

int N;
long long B;

void mul_mat(int** mat1, int** mat2, int** result_mat) {
    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            result_mat[i][j] = 0;
            for(int k=0; k < N; k++) {
                result_mat[i][j] += mat1[i][k] * mat2[k][j];
                result_mat[i][j] %= 1000;
            }
        }
    }
}

void copy_mat(int** mat1, int** mat2) {
    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            mat1[i][j] = mat2[i][j];
        }
    }
}

int** power_mat(int** mat, long long n) {
    int** result_mat = new int*[N];
    int** powered_mat = new int*[N];

    for(int i=0; i < N; i++) {
        result_mat[i] = new int[N];
        powered_mat[i] = new int[N];

        for(int j=0; j < N; j++) {
            if(i == j) {
                powered_mat[i][j] = 1;
            } else {
                powered_mat[i][j] = 0;
            }
        }
    }

    while(n > 0) {
        if(n % 2 == 1) {
            mul_mat(powered_mat, mat, result_mat);
            SWAP(int**, powered_mat, result_mat);
        }
        n >>= 1;
        mul_mat(mat, mat, result_mat);
        SWAP(int**, mat, result_mat);
    }

    SWAP(int**, mat, powered_mat);

    for(int i=0; i < N; i++) {
        delete[] powered_mat[i];
        delete[] result_mat[i];
    }
    delete[] powered_mat;
    delete[] result_mat;

    return mat;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> B;
    int** A = new int*[N];

    for(int n1=0; n1 < N; n1++) {
        A[n1] = new int[N];
        for(int n2=0; n2 < N; n2++) {
            cin >> A[n1][n2];
        }
    }

    A = power_mat(A, B);

    for(int n1=0; n1 < N; n1++) {
        for(int n2=0; n2 < N; n2++) {
            cout << A[n1][n2] << ' ';
        }
        cout << '\n';
    }

    for(int i=0; i < N; i++) {
        delete[] A[i];
    }
    delete[] A;
}