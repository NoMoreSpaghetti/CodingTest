#include <iostream>
using namespace std;

bool solution(string paper) {
    if(paper.size() == 1) {
        return true;
    }

    int mid = paper.size() / 2;
    bool valid = true;

    for(int i=0; i < mid; i++) {
        if(paper[i] == paper[paper.size() - 1 - i]) {
            valid = false;
            break;
        }
    }

    if(!valid) {
        return false;
    } else {
        return solution(paper.substr(0, mid)) && solution(paper.substr(mid + 1, mid));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while(T--) {
        string paper;
        cin >> paper;

        if(solution(paper)) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}