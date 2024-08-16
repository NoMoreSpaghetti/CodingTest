#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<string> paper(N, "");
    for(int i=0; i < N; i++) {
        cin >> paper[i];
    }

    int mid = M >> 1;
    for(int i=0; i < N; i++) {
        for(int j=0; j < mid; j++) {
            if(paper[i][M - 1 - j] == '.') {
                paper[i][M - 1 - j] = paper[i][j];
            }
            if(paper[i][j] == '.') {
                paper[i][j] = paper[i][M - 1 - j];
            }
        }
    }

    for(int i=0; i < N; i++) {
        cout << paper[i] << '\n';
    }
}