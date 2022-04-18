#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> vec(N);

    for(int i=0; i < N; i++) {
        cin >> vec[i];
    }

    int answer = 0;
    for(int i=N - 2; i >= 0; i--) {
        if(vec[i + 1] <= vec[i]) {
            answer += vec[i] - (vec[i + 1] - 1);
            vec[i] = vec[i + 1] - 1;
        }
    }

    cout << answer << '\n';
}