#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;


int N, K;
unordered_set<string> us;

bool is_sorted(string& s) {
    for(int i=0; i < N; i++) {
        if(s[i - 1] > s[i]) {
            return false;
        }
    }
    return true;
}

int bfs(string start_s) {
    queue<pair<string, int>> q;
    q.push({start_s, 0});
    int min_cnt = INT32_MAX;
    us.insert(start_s);

    if(is_sorted(start_s)) {
        return 0;
    }

    while(!q.empty()) {
        string cur_s = q.front().first;
        int cnt = q.front().second;
        q.pop();

        for(int i=0; i < N - K + 1; i++) {
            string new_s(cur_s);
            for(int j=0; j < K / 2; j++) {
                new_s[i + j] = cur_s[i + K - 1 - j];
                new_s[i + K - 1 - j] = cur_s[i + j];
            }

            auto it = us.find(new_s);
            if(it == us.end()) {
                us.insert(new_s);
                if(is_sorted(new_s)) {
                    min_cnt = min(min_cnt, cnt + 1);
                } else {
                    q.push({new_s, cnt + 1});
                }
            }
            
        }
    }

    return min_cnt;
}

void solution(string& s) {
    int cnt = bfs(s);

    if(cnt == INT32_MAX) {
        cout << -1 << '\n';
    } else {
        cout << cnt << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    string s;
    char c;

    for(int i=0; i < N; i++) {
        cin >> c;
        s += c;
    }

    solution(s);
}