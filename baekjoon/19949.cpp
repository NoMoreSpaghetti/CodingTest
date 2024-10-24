#include <iostream>
#include <vector>
using namespace std;

vector<int> answers;
int ans = 0;

void recursive(int idx, int num, int cnt, int score) {
    if(idx == 9) {
        score += (num == answers[idx]) ? 1 : 0;
        if(score >= 5) {
            ans++;
        }
        return;
    }

    if(num == answers[idx]) {
        score++;
    }

    if(cnt != 2) {
        recursive(idx + 1, num, cnt + 1, score);
    }
    for(int i=1; i <= 5; i++) {
        if(num == i) continue;
        recursive(idx + 1, i, 1, score);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    answers = vector<int>(10, 0);
    for(int i=0; i < 10; i++) {
        cin >> answers[i];
    }

    for(int i=1; i <= 5; i++) {
        recursive(0, i, 1, 0);
    }

    cout << ans << '\n';
}