#include <iostream>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <limits>
using namespace std;

int T, N, V;
int points[20][2];
int vec[2];
bool visited[20] = {0};
long long min_square_len = LLONG_MAX;

long long calc_square_len(long long x, long long y) {
    long long square_len = x * x + y * y;
    return square_len;
}

void recursive(int cur, int s, long long x, long long y) {
    if(cur == N) {
        return;
    } else if(s == V) {
        min_square_len = min(min_square_len, calc_square_len(x, y));
        return;
    } else {
        recursive(cur + 1, s + 1, x - 2 * points[cur][0], y - 2 * points[cur][1]);
        recursive(cur + 1, s, x, y);
    }
}

double get_min_len() {
    min_square_len = LLONG_MAX;
    memset(visited, false, sizeof(visited));
    V = N / 2;
    recursive(0, 0, vec[0], vec[1]);
    return sqrt(min_square_len);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(std::numeric_limits<double>::max_digits10);

    cin >> T;
    for(int t=0; t < T; t++) {
        vec[0] = vec[1] = 0;
        cin >> N;
        for(int n=0; n < N; n++) {
            cin >> points[n][0] >> points[n][1];
            vec[0] += points[n][0];
            vec[1] += points[n][1];
        }
        cout << get_min_len() << '\n';
    }
}