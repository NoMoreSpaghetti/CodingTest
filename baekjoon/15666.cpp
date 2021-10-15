#include <iostream>
#include <cstring>
#include <algorithm>
#define SWAP(type, x, y) do {type temp; temp = x; x = y; y = temp;} while(0)
using namespace std;

int N, M;
int nums[8];
int prev_ary[8];

int partition(int ary[], int left, int right) {
    int pivot = ary[right];
    int low = left - 1;

    for(int high = left; high <= right - 1; high++) {
        if(ary[high] < pivot) {
            low++;
            SWAP(int, ary[low], ary[high]);
        }
    }
    SWAP(int, ary[low + 1], ary[right]);

    return low + 1;
}

void quick_sort(int ary[], int left, int right)
{
	if(left < right)
	{
		int q = partition (ary, left, right);
		quick_sort(ary, left, q - 1);
		quick_sort(ary, q + 1, right);
	}
}

int unique_array(int ary[], int size) {
    int end = 1;
    for(int i=1; i < size; i++) {
        if(ary[i-1] == ary[i]) {
            continue;
        }
        ary[end] = ary[i];
        end++;
    }

    return end;
}

void recursive(int m, int k, string s) {
    for(int i=k; i < N; i++) {
        if(m == 1) {
            cout << s << nums[i] << '\n';
        } else {
            recursive(m - 1, i, s + to_string(nums[i]) + ' ');
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int n=0; n < N; n++) {
        cin >> nums[n];
    }

    quick_sort(nums, 0, N - 1);

    N = unique_array(nums, N);

    string s;
    recursive(M, 0, s);
}