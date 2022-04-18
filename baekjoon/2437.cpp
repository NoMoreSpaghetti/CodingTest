#include <iostream>
#include <vector>
#include <algorithm>
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

    sort(vec.begin(), vec.end());

    int sum = vec[0];
    int answer = 0;
    if(vec[0] > 1) {
        answer = 1;
    } else {
        for(int i=1; i < N; i++) {
            if(vec[i] > sum + 1) {
                answer = sum + 1;
                break;
            }
            sum += vec[i];
        }
        if(answer == 0) {
            answer = sum + 1;
        }
    }

    cout << answer << '\n';
}