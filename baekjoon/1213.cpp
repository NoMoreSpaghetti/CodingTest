#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    vector<int> num_alphabets(26, 0);
    for(const auto& c : s) {
        num_alphabets[c - 'A']++;
    }

    int num_odd_num_alps = 0;
    int odd_num_alp_idx = -1;

    bool valid_name = true;

    for(int i=0; i < num_alphabets.size(); i++) {
        if(num_alphabets[i] % 2 == 1) {
            num_odd_num_alps++;
            if(num_odd_num_alps > s.size() % 2) {
                valid_name = false;
                break;
            }
            odd_num_alp_idx = i;
            num_alphabets[i]--;
        }
        num_alphabets[i] /= 2;
    }

    if(valid_name) {
        string answer = "";
        for(int i=0; i < num_alphabets.size(); i++) {
            for(int j=0; j < num_alphabets[i]; j++) {
                answer += i + 'A';
            }
        }

        cout << answer;
        if(odd_num_alp_idx != -1) {
            cout << static_cast<char>('A' + odd_num_alp_idx);
        }
        reverse(answer.begin(), answer.end());
        cout << answer << '\n';

    } else {
        cout << "I'm Sorry Hansoo" << '\n';
    }
}