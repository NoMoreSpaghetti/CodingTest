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
    sort(vec.begin(), vec.end(), greater<int>());

    int answer = 0;
    int i=1;
    for(i=0; i < N; i++) {
        if(vec[i] <= 0) {
            break;
        } else if(i + 1 < N) {
            if(vec[i + 1] > 1) {
                answer += vec[i] * vec[i + 1];
                i++;
            } else if(vec[i + 1] == 1) {
                answer += vec[i] + vec[i + 1];
                i++;
            } else {
                answer += vec[i];
                i++;
                break;
            }
        } else {
            answer += vec[i];
        }
    }

    for(int j = N - 1; j >= i; j--) {
        if(j - 1 >= i) {
            answer += vec[j - 1] * vec[j];
            j--;
        } else {
            answer += vec[j];
        }
    }

    cout << answer << '\n';
}