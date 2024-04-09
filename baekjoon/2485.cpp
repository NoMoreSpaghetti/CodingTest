#include <iostream>
#include <vector>
using namespace std;

int N;

long long get_gcd(long long a, long long b) {
    long long c;

    while(b != 0) {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<int> trees(N, 0);
    vector<int> intervals(N - 1, 0);

    cin >> trees[0];
    for(int i=1; i < N; i++) {
        cin >> trees[i];
        intervals[i - 1] = trees[i] - trees[i - 1];
    }

    long long interval;
    long long min_interval = intervals[0];
    for(int i=1; i < N - 1; i++) {
        min_interval = get_gcd(min_interval, intervals[i]);
    }

    int num_need_trees = 0;
    for(int i=0; i < N - 1; i++) {
        num_need_trees += (intervals[i] / min_interval) - 1;
    }

    cout << num_need_trees << '\n';
}