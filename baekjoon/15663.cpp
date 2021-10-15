#include <iostream>
#include <algorithm>
#define SWAP(type, x, y) do {type temp; temp = x; x = y; y = temp;} while(0)
using namespace std;

int N, M;
int nums[8];
int prev_ary[8];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int n=0; n < N; n++) {
        cin >> nums[n];
    }

    sort(nums, nums + N);

    copy(nums, nums + N, prev_ary);

    for(int i=0; i < M; i++) {
        cout << nums[i] << ' ';
    }
    cout << '\n';
    
    do {
        bool same = true;
        for(int i=0; i < M; i++) {
            if(prev_ary[i] != nums[i]) {
                same = false;
            }
        }

        if(same == false) {
            copy(nums, nums + N, prev_ary);
            for(int i=0; i < M; i++) {
                cout << nums[i] << ' ';
            }
            cout << '\n';
        }
        
    } while(next_permutation(nums, nums + N));
}