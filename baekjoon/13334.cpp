#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int h, o, d, start, end;

    cin >> N;
    vector<pair<int, int>> dists;
    // pq는 시작점 기준으로 정렬. {시작점, 끝점}
    priority_queue<pair<int, int>> pq;
    // pq_end_points는 끝점 기준으로 정렬. {끝점}
    priority_queue<int> pq_end_points;

    for(int i=0; i < N; i++) {
        cin >> h >> o;
        if(h > o) swap(h, o);
        pq.push({h, o});
    }
    cin >> d;

    int ans = 0;
    // 시작점이 가장 멀리 있는 line부터 검사
    // 해당 line의 시작점을 철로의 시작점으로 사용
    while(!pq.empty()) {
        int num_lines = 0;

        // 철로의 시작점과 끝점
        start = pq.top().first;
        end = start + d;
        
        // 이전에 검사했던 line 검사
        // 끝점이 철로를 벗어나면 제거
        while(!pq_end_points.empty() && pq_end_points.top() > end) {
            pq_end_points.pop();
        }
        // 이전에 검사했던 line들은 모두 현재 철로에 포함됨
        num_lines += pq_end_points.size();

        // 시작점이 같은 line 검사
        while(!pq.empty() && pq.top().first == start) {
            if(pq.top().second <= end) {
                num_lines++;
                pq_end_points.push(pq.top().second);
            }
            pq.pop();
        }

        ans = max(ans, num_lines);
    }

    cout << ans << '\n';
}