#include <iostream>
#include <vector>
#include <algorithm>
#define SWAP(type, a, b) do {type temp = a; a = b; b = temp;} while(0);
using namespace std;

int get_max_idx(int start_idx, int size, vector<int>& vec) {
    int max_val = vec[start_idx];
    int max_idx = start_idx;
    for(int i=start_idx + 1; i <= start_idx + size; i++) {
        if(vec[i] > max_val) {
            max_val = vec[i];
            max_idx = i;
        }
    }
    return max_idx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, S, inp;
    cin >> N;

    vector<int> vec;

    for(int i=0; i < N; i++) {
        cin >> inp;
        vec.push_back(inp);
    }

    cin >> S;

    int start_idx = 0;
    // 원소가 하나만 남은 경우는 비교할 필요가 없으니 i >= 0이 아닌 i > 0
    for(int i=N; i > 0; i--) {
        int start_idx = N - i;
        int size = min(S, i);
        int max_idx = get_max_idx(start_idx, size, vec);
        for(int j=max_idx; j > start_idx; j--) {
            SWAP(int, vec[j], vec[j-1]);
        }
        S -= max_idx - start_idx;
        if(S == 0) {
            break;
        }
    }

    for(int item: vec) {
        cout << item << ' ';
    }
    cout << '\n';
}