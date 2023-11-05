#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, tower;
    cin >> N;

    vector<pair<int, int>> s;

    int answer = 0;
    cin >> tower;
    s.push_back({1, tower});
    cout << 0 << ' ';

    for(int i=1; i < N; i++) {
        answer = 0;
        cin >> tower;
        for(int j=s.size() - 1; j >= 0; j--) {
            if(s[j].second > tower) {
                answer = s[j].first;
                break;
            } else {
                s.pop_back();
            }
        }

        s.push_back({i + 1, tower});
        cout << answer << ' ';
    }
}