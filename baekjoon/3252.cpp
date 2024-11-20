#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int ConvertStrTimeToInt(string time_str) {
    int dot_pos = time_str.find('.');
    int return_val = 0;
    return_val += stoi(time_str.substr(dot_pos + 1, 2));
    return_val += stoi(time_str.substr(0, dot_pos)) * 100;
    return return_val;
}

priority_queue<pair<int, int>> Round(int num, const vector<int>& indices) {
    priority_queue<pair<int, int>> round_result;
    string time_str;
    char c;

    cin >> time_str;

    int starter_time = ConvertStrTimeToInt(time_str);
    round_result.push({-starter_time, indices[0]});

    for(int i=1; i < num; i++) {
        cin >> c;
        cin >> time_str;

        int interval = ConvertStrTimeToInt(time_str);
        pair<int, int> cur_info;

        if(c == '+') {
            cur_info.first = round_result.top().first - interval;
        } else {
            cur_info.first = round_result.top().first + interval;
        }

        cur_info.second = indices[i];
        round_result.push(cur_info);
    }

    return round_result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> indices(N, 0);
    for(int i=1; i <= N; i++) {
        indices[i - 1] = i;
    }

    priority_queue<pair<int, int>> round_result = Round(N, indices);

    indices.clear();
    for(int i=0; i < M; i++) {
        indices.push_back(round_result.top().second);
        round_result.pop();
    }

    reverse(indices.begin(), indices.end());

    round_result = Round(M, indices);

    for(int i=0; i < 3; i++) {
        cout << round_result.top().second << '\n';
        round_result.pop();
    }
}