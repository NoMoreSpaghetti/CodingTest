#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    int N, len;
    cin >> N >> len;

    vector<int> h_vec(N, 0);

    for(int i=0; i < N; i++) {
        cin >> h_vec[i];
    }

    sort(h_vec.begin(), h_vec.end());
    for(int i=0; i < N; i++) {
        if(h_vec[i] > len) {
            break;
        }
        len++;
    }
    cout << len << '\n';

}