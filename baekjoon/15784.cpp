#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, a, b, jinseo;
    cin >> N >> a >> b;

    vector<vector<int>> classroom(N, vector<int>(N, 0));

    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            cin >> classroom[i][j];
        }
    }

    bool happy = true;
    jinseo = classroom[a - 1][b - 1];
    for(int i=0; i < N; i++) {
        if(classroom[a - 1][i] > jinseo || classroom[i][b - 1] > jinseo) {
            happy = false;
            break;
        }
    }

    if(happy) {
        cout << "HAPPY" << '\n';
    } else {
        cout << "ANGRY" << '\n';
    }
}