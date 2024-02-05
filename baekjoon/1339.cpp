#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int N;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    string s;
    vector<string> strings;
    for(int i=0; i < N; i++) {
        cin >> s;
        reverse(s.begin(), s.end());
        strings.push_back(s);
    }

    int ans = 0;
    int idx_value = 1;
    map<int, int> alp_values;
    for(int i=0; i < 8; i++) {
        for(auto& element: strings) {
            if(element.length() > i) {
                int alp_idx = element[i] - 'A';
                alp_values[alp_idx] += idx_value;
            }
        }
        idx_value *= 10;
    }

    vector<pair<int, int>> v(alp_values.begin(), alp_values.end());
    sort(v.begin(), v.end(), compare);

    int cur_alp_num = 9;
    for(auto& element: v) {
        ans += element.second * cur_alp_num--;
    }

    cout << ans << '\n';
}