#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, k, a, inp;
    cin >> N >> M;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> A;
    priority_queue<int, vector<int>, greater<int>> sushi;
    vector<int> num_sushi_eaten(N, 0);

    for(int i=0; i < N; i++) {
        cin >> k;
        for(int j=0; j < k; j++) {
            cin >> a;
            A.push({a, i});
        }
    }
    
    for(int i=0; i < M; i++) {
        cin >> inp;
        sushi.push(inp);
    }

    while(!sushi.empty()) {
        int cur_sushi = sushi.top();
        sushi.pop();

        while(!A.empty() && A.top().first < cur_sushi) {
            A.pop();
        }

        if(!A.empty() && A.top().first == cur_sushi) {
            num_sushi_eaten[A.top().second]++;
            A.pop();
        }
    }

    for(int i=0; i < N; i++) {
        cout << num_sushi_eaten[i] << ' ';
    }
}