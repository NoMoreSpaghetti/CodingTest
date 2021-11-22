#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int MAX_LEN = 1001;
int N, M;
vector<vector<bool>> singer;
bool visited[1001] = {0};
vector<int> order;

void dfs(int here) {
    visited[here] = true;
    for(int there = 1; there < MAX_LEN; there++) {
        if(singer[here][there] && !visited[there]) {
            dfs(there);
        }
    }
    order.push_back(here);
}

bool topological_sort() {
    for(int i=1; i <= N; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }

    reverse(order.begin(), order.end());

    for(int i=0; i < N; i++) {
        for(int j=i+1; j < N; j++) {
            if(singer[order[j]][order[i]]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, inp, prev;
    singer = vector<vector<bool>>(1001, vector<bool>(1001, false));
    
    cin >> N >> M;
    
    for(int m=0; m < M; m++) {
        cin >> num;
        cin >> prev;
        for(int i=1; i < num; i++) {
            cin >> inp;
            singer[prev][inp] = true;
            prev = inp;
        }
    }

    if(topological_sort()) {
        for(int i=0; i < order.size(); i++) {
            cout << order[i] << '\n';
        }
    } else {
        cout << 0 << '\n';
    }
}