#include <iostream>
#include <stack>
using namespace std;

int lcs[1001][1001] = {0};
int idxes[1001][1001][2] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;
    int s1_len = s1.length();
    int s2_len = s2.length();

    for(int i=0; i < s1_len; i++) {
        for(int j=0; j < s2_len; j++) {
            if(s1[i] == s2[j]) {
                lcs[i+1][j+1] = lcs[i][j] + 1;
                idxes[i+1][j+1][0] = i + 1;
                idxes[i+1][j+1][1] = j + 1;
            } else if(lcs[i][j+1] > lcs[i+1][j]) {
                lcs[i+1][j+1] = lcs[i][j+1];
                idxes[i+1][j+1][0] = idxes[i][j+1][0];
                idxes[i+1][j+1][1] = idxes[i][j+1][1];
            } else {
                lcs[i+1][j+1] = lcs[i+1][j];
                idxes[i+1][j+1][0] = idxes[i+1][j][0];
                idxes[i+1][j+1][1] = idxes[i+1][j][1];
            }
        }
    }

    stack<char> s;
    int i = idxes[s1_len][s2_len][0], j = idxes[s1_len][s2_len][1];
    int new_i, new_j;

    while(i || j) {
        s.push(s1[i - 1]);
        new_i = idxes[i - 1][j - 1][0];
        new_j = idxes[i - 1][j - 1][1];
        i = new_i;
        j = new_j;
    }
    
    cout << lcs[s1.length()][s2.length()] << '\n';

    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }
}