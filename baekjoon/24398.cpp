#include <iostream>
#include <vector>
using namespace std;

int N, Q, K;
int swap_count = 0;
pair<int, int> swap_nums = {0, 0};

int partition(vector<int>& vec, int p, int r) {
    int x = vec[r];
    int i = p - 1;
    for(int j=p; j < r; j++) {
        if(vec[j] <= x) {
            swap(vec[++i], vec[j]);
            swap_count++;
            if(swap_count == K) {
                swap_nums.first = vec[i];
                swap_nums.second = vec[j];
            }
        }
    }
    if(i + 1 != r) {
        swap(vec[i + 1], vec[r]);
        swap_count++;
        if(swap_count == K) {
            swap_nums.first = vec[i + 1];
            swap_nums.second = vec[r];
        }
    }
    return i + 1;
}

int select(vector<int>& vec, int p, int r, int q) {
    if(p == r) {
        return vec[p];
    }

    int t = partition(vec, p, r);
    int k = t - p + 1;
    if(q < k) {
        return select(vec, p, t - 1, q);
    } else if(q == k) {
        return vec[t];
    } else {
        return select(vec, t + 1, r, q - k);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> Q >> K;

    vector<int> vec(N, 0);
    for(int i=0; i < N; i++) {
        cin >> vec[i];
    }

    select(vec, 0, vec.size() - 1, Q);
    if(swap_nums.first == 0) {
        cout << -1 << '\n';
    } else {
        if(swap_nums.first > swap_nums.second) {
            swap(swap_nums.first, swap_nums.second);
        }
        cout << swap_nums.first << ' ' << swap_nums.second << '\n';
    }
}