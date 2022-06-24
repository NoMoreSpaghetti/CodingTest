// 참고: https://yabmoons.tistory.com/339

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<string> board;
vector<vector<bool>> visited;
vector<vector<int>> dp;
int N;
int M;

template <typename LT, typename RT>
pair<LT, RT> operator+(const pair<LT, RT>& l, const pair<LT, RT>& r) {
    return {l.first + r.first, l.second + r.second};
}

template <typename T>
pair<T, T> operator*(const pair<T, T>& l, const T mul_val) {
    return {l.first * mul_val, l.second * mul_val};
}

bool is_available(const pair<int, int>& pos) {
    if(pos.first >= 0 && pos.first < N && pos.second >= 0 && pos.second < M) {
        return true;
    }
    return false;
}

int dfs(const pair<int, int>& pos) {
    const static pair<int, int> directions[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int& dp_val = dp[pos.first][pos.second];
    char& cur_char = board[pos.first][pos.second];

    if(!is_available(pos)) {
        return 0;
    }
    if(cur_char == 'H') {
        return 0;
    }
    if(visited[pos.first][pos.second]) {
        return -1;
    }
    if(dp_val != -1) {
        return dp_val;
    }

    visited[pos.first][pos.second] = true;
    dp_val = 0;
    for(int i=0; i < 4; i++) {
        pair<int, int> next = pos + (directions[i] * (cur_char - '0'));
        int dfs_result = dfs(next);
        if(dfs_result == -1) {
            return -1;
        }

        dp_val = max(dp_val, dfs_result + 1);
    }
    visited[pos.first][pos.second] = false;

    return dp_val;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> N >> M;

    visited = vector<vector<bool>>(N, vector<bool>(M, false));
    dp = vector<vector<int>>(N, vector<int>(M, -1));
    for(int i=0; i < N; i++) {
        cin >> s;
        board.push_back(s);
    }

    cout << dfs({0, 0}) << '\n';
}