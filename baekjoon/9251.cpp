#include <iostream>
#include <string.h>
using namespace std;

int LCS[1001][1001] = {0};

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    for(int i=0; i < s1.length(); i++) {
        for(int j=0; j < s2.length(); j++) {
            if(s1[i] == s2[j]) {
                LCS[i+1][j+1] = LCS[i][j] + 1;
            } else {
                LCS[i+1][j+1] = max(LCS[i][j+1], LCS[i+1][j]);
            }
        }
    }

    cout << LCS[s1.length()][s2.length()] << '\n';
}