#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<long long> dists(N - 1);
    vector<long long> cities(N);

    for(int i=0; i < N - 1; i++) {
        cin >> dists[i];
    }

    for(int i=0; i < N; i++) {
        cin >> cities[i];
    }

    long long answer = 0;

    long long prev_min = cities[0];
    long long dist = dists[0];
    for(int i=1; i < N - 1; i++) {
        if(cities[i] < prev_min) {
            answer += dist * prev_min;
            prev_min = cities[i];
            dist = dists[i];
        } else {
            dist += dists[i];
        }
    }
    answer += dist * prev_min;

    cout << answer << '\n';
}