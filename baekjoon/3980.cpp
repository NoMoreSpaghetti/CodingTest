#include <iostream>
#include <vector>
using namespace std;

int N = 11;
vector<vector<int>> vec;
int ans = 0;

void recursive(int cur, int filled_bit, int sum) {
    if(cur == 11) {
        ans = max(ans, sum);
        return;
    }

    for(int i=0; i < N; i++) {
        if(vec[cur][i] != 0 && (filled_bit & (1 << i)) == 0) {
            recursive(cur + 1, filled_bit | (1 << i), sum + vec[cur][i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int C;
    
    cin >> C;

    while(C--) {
        ans = 0;
        vec = vector<vector<int>>(N, vector<int>(N, 0));
        for(int i=0; i < N; i++) {
            for(int j=0; j < N; j++) {
                cin >> vec[i][j];
            }
        }
        recursive(0, 0, 0);
        cout << ans << '\n';
    }
}