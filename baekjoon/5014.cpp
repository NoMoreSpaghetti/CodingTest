#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int F, S, G, U, D;
vector<bool> visited;

bool check_valid(int num) {
    if(num > 0 && num <= F) {
        return true;
    }
    return false;
}

int bfs(int start) {
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;
    int min_num_button_pressed = -1;

    while(!q.empty()) {
        int cur = q.front().first;
        int num_button_pressed = q.front().second;
        q.pop();

        if(cur == G) {
            min_num_button_pressed = num_button_pressed;
            break;
        }

        int next_vals[2] = {cur + U, cur - D};
        for(auto& next : next_vals) {
            if(check_valid(next) && !visited[next]) {
                q.push({next, num_button_pressed + 1});
                visited[next] = true;
            }
        }
    }

    return min_num_button_pressed;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> F >> S >> G >> U >> D;
    visited = vector<bool>(F + 1, false);

    int answer = bfs(S);
    if(answer == -1) {
        cout << "use the stairs" << '\n';
    } else {
        cout << answer << '\n';
    }
}