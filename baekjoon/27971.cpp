#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, A, B;
vector<bool> valid_num_vec;

int solution() {
    queue<pair<int, int>> q;
    q.push({0, 0});

    while(!q.empty()) {
        int cur = q.front().first;
        int num = q.front().second;
        q.pop();

        if(cur + A <= N && valid_num_vec[cur + A]) {
            valid_num_vec[cur + A] = false;
            if(cur + A == N) {
                return num + 1;
            } else if(cur + A < N) {
                q.push({cur + A, num + 1});
            }
        }
        if(cur + B <= N && valid_num_vec[cur + B]) {
            valid_num_vec[cur + B] = false;
            if(cur + B == N) {
                return num + 1;
            } else if(cur + B < N) {
                q.push({cur + B, num + 1});
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int L, R;
    cin >> N >> M >> A >> B;
    valid_num_vec = vector<bool>(N + 1, true);

    for(int i=0; i < M; i++) {
        cin >> L >> R;
        for(int j=L; j <= R; j++) {
            valid_num_vec[j] = false;
        }
    }

    cout << solution() << '\n';
}