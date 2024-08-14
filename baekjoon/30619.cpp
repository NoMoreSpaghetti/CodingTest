#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M, inp;
    cin >> N;
    vector<int> houses(N + 1, 0);
    vector<int> indexes(N + 1, 0);
    
    for(int i=1; i <= N; i++) {
        cin >> houses[i];
        indexes[houses[i]] = i;
    }

    cin >> M;
    int L, R;
    for(int i=0; i < M; i++) {
        cin >> L >> R;
        
        vector<int> houses_copy(houses);
        vector<int> indexes_copy(indexes);

        for(int i=L; i < R; i++) {
            for(int j=i + 1; j <= R; j++) {
                if(indexes_copy[i] > indexes_copy[j]) {
                    swap(houses_copy[indexes_copy[i]], houses_copy[indexes_copy[j]]);
                    swap(indexes_copy[i], indexes_copy[j]);
                }
            }
        }
        
        for(int j=1; j <= N; j++) {
            cout << houses_copy[j] << ' ';
        }
        cout << '\n';
    }
}