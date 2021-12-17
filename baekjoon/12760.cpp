#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int scores[100] = {0};
    int inp;
    priority_queue<int> pq[100];
    cin >> N >> M;

    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            cin >> inp;
            pq[i].push(inp);
        }
    }

    for(int i=0; i < M; i++) {
        int max_val = 0;
        vector<int> max_val_idx;
        for(int j=0; j < N; j++) {
            int val = pq[j].top();
            pq[j].pop();
            if(val > max_val) {
                max_val = val;
                max_val_idx.clear();
                max_val_idx.push_back(j);
            } else if(val == max_val) {
                max_val_idx.push_back(j);
            }
        }
        for(int i=0; i < max_val_idx.size(); i++) {
            scores[max_val_idx[i]]++;
        }
    }

    vector<int> ans;
    int max_score = 0;
    for(int i=0; i < N; i++) {
        if(scores[i] > max_score) {
            max_score = scores[i];
            ans.clear();
            ans.push_back(i + 1);
        } else if(scores[i] == max_score) {
            ans.push_back(i + 1);
        }
    }

    for(int i=0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
}