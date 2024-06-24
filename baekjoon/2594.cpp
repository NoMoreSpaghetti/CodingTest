#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int convert_HHMM_to_M(int time) {
    return (time / 100) * 60 + time % 100;
}

int convert_M_to_HHMM(int time) {
    return time / 60 * 100 + time % 60;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, start, end;
    cin >> N;

    vector<pair<int, int>> schedule;
    schedule.push_back({convert_HHMM_to_M(1000), convert_HHMM_to_M(1000)});
    schedule.push_back({convert_HHMM_to_M(2200), convert_HHMM_to_M(2200)});
    for(int i=0; i < N; i++) {
        cin >> start >> end;
        schedule.push_back({convert_HHMM_to_M(start) - 10, convert_HHMM_to_M(end) + 10});
    }

    sort(schedule.begin(), schedule.end());

    int max_interval = 0;
    int last_time = schedule[0].second;
    for(int i=1; i < schedule.size(); i++) {
        max_interval = max(max_interval, schedule[i].first - last_time);
        last_time = max(last_time, schedule[i].second);
    }

    cout << max_interval << '\n';
}