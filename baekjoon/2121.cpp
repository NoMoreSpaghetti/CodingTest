#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, A, B, x, y;
    cin >> N >> A >> B;

    unordered_map<int, unordered_set<int>> um;

    for(int i=0; i < N; i++) {
        cin >> x >> y;
        um[x].insert(y);
    }

    int answer = 0;
    for(auto& element: um) {
        int bottom_left_x = element.first;
        if(um.find(bottom_left_x + A) != um.end()) {
            int bottom_right_x = bottom_left_x + A;
            for(const auto& y: element.second) {
                if(element.second.find(y + B) != element.second.end() &&
                um[bottom_right_x].find(y) != um[bottom_right_x].end() &&
                um[bottom_right_x].find(y + B) != um[bottom_right_x].end()) {
                    answer++;
                }
            }
        }
    }

    cout << answer << '\n';
}