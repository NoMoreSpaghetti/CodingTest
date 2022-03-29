#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> tree[50];
int parent[50] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, D, temp, answer = 0;
    int root = 0;
    cin >> N;

    for(int i=0; i < N; i++) {
        cin >> temp;
        if(temp != -1) {
            tree[temp].push_back(i);
        } else {
            root = i;
        }
        parent[i] = temp;
    }

    cin >> D;

    if(D != root) {
        vector<int>& D_parent = tree[parent[D]];
        D_parent.erase(remove(D_parent.begin(), D_parent.end(), D), D_parent.end());

        queue<int> q;
        
        q.push(root);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            if(tree[cur].size() == 0) {
                answer++;
            } else {
                for(auto& element : tree[cur]) {
                    q.push(element);
                }
            }
        }
    }

    cout << answer << '\n';
}