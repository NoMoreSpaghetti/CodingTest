#include <iostream>
#include <vector>
using namespace std;

int lcs(string s1, string s2, string s3) {
    vector<vector<vector<int>>> vec(s1.size() + 1, vector<vector<int>>(s2.size() + 1, vector<int>(s3.size() + 1, 0)));

    for(int i=0; i < s1.size(); i++) {
        for(int j=0; j < s2.size(); j++) {
            for(int k=0; k < s3.size(); k++) {
                if(s1[i] == s2[j] && s2[j] == s3[k]) {
                    vec[i + 1][j + 1][k + 1] = vec[i][j][k] + 1;
                } else {
                    vec[i + 1][j + 1][k + 1] = max(max(vec[i + 1][j + 1][k], vec[i + 1][j][k + 1]), vec[i][j + 1][k + 1]);
                }
            }
        }
    }

    return vec[s1.size()][s2.size()][s3.size()];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    cout << lcs(s1, s2, s3) << '\n';
}