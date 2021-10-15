#include <iostream>
#include <cstring>
#define SWAP(type, a, b) do {type temp; temp = a; a = b; b = temp;} while(0)
using namespace std;

int N, M;
int nums[8];
bool visited[8];

int partition(int ary[], int left, int right) {
    int pivot = ary[right];
    int low = left - 1;
    for(int high = left; high <= right; high++) {
        if(ary[high] < pivot) {
            low++;
            SWAP(int, ary[low], ary[high]);
        }
    }
    SWAP(int, ary[right], ary[low + 1]);

    return low + 1;
}

void quick_sort(int ary[], int left, int right) {
    if(left < right) {
        int q = partition(ary, left, right);
        quick_sort(ary, left, q - 1);
        quick_sort(ary, q + 1, right);
    }
}

void recursive(string s, int cur_idx) {
    if(cur_idx == M) {
        cout << s << '\n';
        return;
    }
    for(int i=0; i < N; i++) {
        if(visited[i] == false) {
            string new_s = s + to_string(nums[i]) + ' ';
            visited[i] = true;
            recursive(new_s, cur_idx + 1);
            visited[i] = false;
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

    string s = "";
    recursive(s, 0);
}