#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, inp, answer = 0;
    cin >> N;

    vector<bool> vec(N + 3, false);
    vector<bool> new_vec(N + 3, false);

    for(int i=0; i < N; i++) {
        cin >> inp;
        if(inp) {
            vec[i] = true;
        }
    }

    for(int i=0; i < N; i++) {
        if(vec[i] != new_vec[i]) {
            new_vec[i] = !new_vec[i];
            new_vec[i + 1] = !new_vec[i + 1];
            new_vec[i + 2] = !new_vec[i + 2];
            answer++;
        }
    }

    cout << answer << '\n';
}