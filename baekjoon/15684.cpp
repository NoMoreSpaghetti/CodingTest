#include <iostream>
#include <vector>
using namespace std;

int N, M, H;

vector<vector<bool>> lines;

bool CheckSolved() {
    for(int i=0; i < N; i++) {
        int cur = i;
        for(int j=0; j < H; j++) {
            if(cur < N - 1 && lines[j][cur]) {
                cur++;
            } else if(cur >= 1 && lines[j][cur - 1]) {
                cur--;
            }
        }
        if(cur != i) return false;
    }
    return true;
}

void PrintLines() {
    cout << '\n';
    for(int i=0; i < H; i++) {
        for(int j=0; j < N; j++) {
            cout << "│  ";
        }
        cout << '\n';
        for(int j=0; j < N - 1; j++) {
            if(lines[i][j]) {
                cout << " ─ ";
            } else {
                cout << "   ";
            }
        }
        cout << '\n';
    }
    for(int j=0; j < N; j++) {
        cout << "│  ";
    }
}

int Recursive(int cnt, int y, int x) {
    int ans = 4;

    if(cnt >= 3 || y >= H) {
        if(CheckSolved()) {
            return cnt;
        }
        return 4;
    }

    if(CheckSolved()) {
        return cnt;
    }

    // 이번 줄에 추가하는 경우
    for(int i=x; i < N - 1; i++) {
        if(lines[y][i] == false &&
        (i + 1 == N - 1 || lines[y][i + 1] == false) &&
        (i - 1 < 0 || lines[y][i - 1] == false)) {
            lines[y][i] = true;
            ans = min(ans, Recursive(cnt + 1, y, i + 2));
            lines[y][i] = false;
        }
    }

    // 이번 줄에 추가하지 않는 경우
    ans = min(ans, Recursive(cnt, y + 1, 0));
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> H;

    lines = vector<vector<bool>>(H, vector<bool>(N - 1, false));

    int a, b;
    for(int i=0; i < M; i++) {
        cin >> a >> b;
        lines[a - 1][b - 1] = true;
    }

    int ans = Recursive(0, 0, 0);
    if(ans == 4) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
}