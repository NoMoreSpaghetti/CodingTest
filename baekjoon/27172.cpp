#include <iostream>
#include <vector>
#define MAX_NUM 1000001
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    bool exists[MAX_NUM] = {0};
    int scores[MAX_NUM] = {0};
    cin >> N;

    vector<int> players(N, -1);
    for(int i=0; i < N; i++) {
        cin >> players[i];
        exists[players[i]] = true;
    }

    for(int i=0; i < N; i++) {
        int num = players[i] * 2;
        while(num < MAX_NUM) {
            if(exists[num]) {
                scores[num]--;
                scores[players[i]]++;
            }
            num += players[i];
        }
    }

    for(int i=0; i < N; i++) {
        cout << scores[players[i]] << ' ';
    }
}