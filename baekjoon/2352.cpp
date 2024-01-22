#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> lines;

int binary_search(vector<int>& vec, int left, int right, int val) {
    while(left < right) {
        int mid = (left + right) / 2;
        if(vec[mid] < val) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return right;
}

int lis() {
    vector<int> cache(N, -1);
    cache[0] = lines[0];
    int cache_idx = 0;
    for(int i=1; i < N; i++) {
        if(cache[cache_idx] < lines[i]) {
            cache[++cache_idx] = lines[i];
        } else {
            int idx = binary_search(cache, 0, cache_idx, lines[i]);
            cache[idx] = lines[i];
        }
    }
    return cache_idx + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    lines = vector<int>(N, 0);

    for(int i=0; i < N; i++) {
        cin >> lines[i];
    }

    cout << lis() << '\n';
}