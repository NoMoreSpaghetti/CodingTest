#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, answer = 0;
    cin >> N;

    string inp;

    while(N--) {
        cin >> inp;
        vector<bool> visited(26, false);

        int str_idx = 0;
        while(str_idx < inp.length()) {
            if(!visited[inp[str_idx] - 'a']) {
                visited[inp[str_idx] - 'a'] = true;
                while(str_idx + 1 < inp.length() && inp[str_idx] == inp[str_idx + 1]) {
                    str_idx++;
                }
                str_idx++;
            } else {
                break;
            }
        }
        if(str_idx == inp.length()) {
            answer++;
        }
    }
    cout << answer << '\n';
}