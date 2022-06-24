#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool binary_search(vector<int>& vec, const int& n) {
    int left = 0;
    int right = vec.size() - 1;
    while(left <= right) {
        int mid = (left + right) / 2;

        if(vec[mid] == n) {
            return true;
        } else if(vec[mid] > n) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, inp;
    vector<int> a;
    cin >> N;

    for(int i=0; i < N; i++) {
        cin >> inp;
        a.push_back(inp);
    }

    sort(a.begin(), a.end());

    cin >> M;
    for(int i=0; i < M; i++) {
        cin >> inp;
        if(binary_search(a, inp)) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}