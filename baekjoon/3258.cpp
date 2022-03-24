#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Z, M, temp;
    vector<bool> field(1001, 0);
    cin >> N >> Z >> M;

    for(int i=0; i < M; i++) {
        cin >> temp;
        field[temp] = true;
    }

    int K = 1;
    for(; K < Z; K++) {
        int cur = 1;
        while(!field[cur]) {
            cur = (cur - 1 + K) % N + 1;
            if(cur == 1) {
                break;
            } else if(cur == Z) {
                break;
            }
        }
        if(cur == Z) {
            break;
        }
    }
    
    cout << K << '\n';
}