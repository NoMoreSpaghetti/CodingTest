#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> nums;

void recursive(int size, int bit) {
    if(size == M) {
        for(int i=0; i < size; i++) {
            cout << nums[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=1; i <= N; i++) {
        if(bit & (1 << i)) {
            continue;
        }

        nums.push_back(i);
        recursive(size + 1, bit | (1 << i));
        nums.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    recursive(0, 0);
}