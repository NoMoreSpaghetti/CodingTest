#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int T, n;
int students[100001];
bool visited[100001];
int ans = 0;

void dfs(int start) {
    stack<int> s;
    s.push(start);
    while(true) {
        int here = s.top();

        visited[here] = true;
        int there = students[here];
        if(visited[there] == false) {
            s.push(there);
        } else if(there == start) {
            break;
        } else {
            int num = 0;
            while(!s.empty()) {
                here = s.top();
                s.pop();
                num++;
                if(here == there) {
                    num = 0;
                }
            }
            ans += num;
            break;
        }
    }
}

void dfs_all() {
    memset(visited, false, sizeof(visited));
    for(int i=1; i <= n; i++) {
        if(visited[i] == false) {
            dfs(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int t=0; t < T; t++) {
        cin >> n;
        for(int i=1; i <= n; i++) {
            cin >> students[i];
        }
        dfs_all();

        cout << ans << '\n';
        ans = 0;
    }
}