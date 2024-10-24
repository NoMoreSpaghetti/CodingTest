#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N;

map<char, int> color_map = {{'R', 0}, {'G', 1}, {'B', 2}};

int GetDist(const int& a, const int& b) {
    return (b - a + 3) % 3;
}

int solution(vector<int> bulbs, int target) {
    int ans = 0;
    for(int i=0; i < N - 2; i++) {
        while(i < N - 2 && bulbs[i] == target) {
            i++;
        }

        if(i >= N - 2) break;
        
        int dist = GetDist(bulbs[i], target);

        for(int j=i; j < i + 3; j++) {
            bulbs[j] = (bulbs[j] + dist) % 3;
        }
        ans += dist;
    }

    for(int i=N - 2; i < N; i++) {
        if(bulbs[i] != target) {
            return INT32_MAX;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<int> bulbs(N, 0);

    string inp;
    cin >> inp;    

    for(int i=0; i < N; i++) {
        bulbs[i] = color_map[inp[i]];
    }

    int ans = INT32_MAX;
    for(int target=0; target < 3; target++) {
        ans = min(ans, solution(bulbs, target));
    }

    if(ans == INT32_MAX) {
        ans = -1;
    }
    cout << ans << '\n';
}