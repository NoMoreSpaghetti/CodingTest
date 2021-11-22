#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N, M, A, B;
vector<int> v[32001];
bool visited[32001] = {0};
stack<int> s;

void dfs(int here) {
    visited[here] = true;
    for(int there : v[here]) {
        if(visited[there] == false) {
            dfs(there);
        }
    }
    s.push(here);
}

void topological_sort() {
    for(int i=N; i > 0; i--) {
        if(visited[i] == false) {
            dfs(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int m=0; m < M; m++) {
        cin >> A >> B;
        v[A].push_back(B);
    }

    topological_sort();

    while(!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
}