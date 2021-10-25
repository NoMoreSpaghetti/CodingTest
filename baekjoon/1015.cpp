#include <iostream>
#define SWAP(type, a, b) do {type temp = a; a = b; b = temp;} while(0);
using namespace std;


int partition(int ary1[], int ary2[], int left, int right) {
    int pivot = ary1[right];
    int low = left - 1;
    for(int high = left; high <= right; high++) {
        if(ary1[high] < pivot) {
            low++;
            SWAP(int, ary1[low], ary1[high]);
            SWAP(int, ary2[low], ary2[high]);
        } else if(ary1[high] == pivot && ary2[high] < ary2[right]) {
            low++;
            SWAP(int, ary1[low], ary1[high]);
            SWAP(int, ary2[low], ary2[high]);
        }
    }
    SWAP(int, ary1[right], ary1[low + 1]);
    SWAP(int, ary2[right], ary2[low + 1]);

    return low + 1;
}

void quick_sort(int ary1[], int ary2[], int left, int right) {
    if(left < right) {
        int q = partition(ary1, ary2, left, right);
        quick_sort(ary1, ary2, left, q - 1);
        quick_sort(ary1, ary2, q + 1, right);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, num;
    int A[50], s[50];
    cin >> N;

    for(int i=0; i < N; i++) {
        cin >> A[i];
        s[i] = i;
    }

    quick_sort(A, s, 0, N - 1);

    for(int i=0; i < N; i++) {
        A[i] = i;
    }

    quick_sort(s, A, 0, N - 1);

    for(int i=0; i < N; i++) {
        cout << A[i] << ' ';
    }
}