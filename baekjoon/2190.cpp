#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N;
vector<pair<long long, long long>> dots;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long A, B;
    cin >> N >> A >> B;

    dots = vector<pair<long long, long long>>(N, {0, 0});
    set<long long> candidates_y;
    set<long long> candidates_x;

    for(int i=0; i < N; i++) {
        cin >> dots[i].second >> dots[i].first;
        candidates_y.insert(dots[i].first);
        candidates_x.insert(dots[i].second);
    }

    sort(dots.begin(), dots.end());

    int ans = 0;
    int dot_start_idx = 0;

    for(auto& y: candidates_y) {
        for(auto& x: candidates_x) {
            int num_dots = 0;

            if(dot_start_idx < N && dots[dot_start_idx].first == y && dots[dot_start_idx].second == x) {
                num_dots++;
                dot_start_idx++;
            }

            for(int dot_idx=dot_start_idx; dot_idx < N; dot_idx++) {
                if(dots[dot_idx].first <= y + B) {
                    if(dots[dot_idx].second >= x && dots[dot_idx].second <= x + A) {
                        num_dots++;
                    }
                } else {
                    break;
                }
            }
            ans = max(ans, num_dots);
        }
    }

    cout << ans << '\n';
}