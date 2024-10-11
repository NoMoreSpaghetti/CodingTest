#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;

vector<vector<int>> next_tasks;
vector<int> in_degrees;
vector<int> times;
vector<int> complete_times;

int TopologySort() {
    queue<int> q;
    int cur;
    int ans = 0;

    for(int i=1; i <= N; i++) {
        if(in_degrees[i] == 0) {
            complete_times[i] = times[i];
            q.push(i);
        }
    }

    for(int i=1; i <= N; i++) {
        // 사이클 확인
        if(q.empty()) {
            return -1;
        }

        int cur = q.front();
        ans = max(ans, complete_times[cur]);
        q.pop();

        for(auto& next_task: next_tasks[cur]) {
            complete_times[next_task] = max(complete_times[next_task], complete_times[cur]);
            if(--in_degrees[next_task] == 0) {
                complete_times[next_task] += times[next_task];
                q.push(next_task);
            }
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    next_tasks = vector<vector<int>>(N + 1, vector<int>());
    in_degrees = vector<int>(N + 1, 0);
    times = vector<int>(N + 1, 0);
    complete_times = vector<int>(N + 1, 0);

    int num_prev_tasks, prev_task;
    for(int i=1; i <= N; i++) {
        cin >> times[i] >> num_prev_tasks;

        for(int j=0; j < num_prev_tasks; j++) {
            cin >> prev_task;
            next_tasks[prev_task].push_back(i);
            in_degrees[i]++;
        }
    }

    cout << TopologySort() << '\n';
}