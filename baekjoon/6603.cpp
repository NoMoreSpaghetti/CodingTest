#include <iostream>
#include <vector>
using namespace std;

int k;
vector<int> S;
int p_ary[6];

void print_ary(int ary[]) {
    for(int i=0; i < 6; i++) {
        cout << ary[i] << ' ';
    }
    cout << '\n';
}

void recursive(int idx, int size) {
    if(size == 6) {
        print_ary(p_ary);
    } else if(k - idx < 6 - size) {
        return;
    } else {
        for(int i=idx; i < k; i++) {
            p_ary[size] = S[i];
            recursive(i + 1, size + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int inp;
    cin >> k;
    while(k != 0) {
        S.clear();
        for(int i=0; i < k; i++) {
            cin >> inp;
            S.push_back(inp);
        }
        recursive(0, 0);
        cout << '\n';
        cin >> k;
    }
}