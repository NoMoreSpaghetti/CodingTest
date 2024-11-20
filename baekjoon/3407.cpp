#include <iostream>
#include <vector>
using namespace std;

vector<char> element1 = { 'h', 'b', 'c', 'n', 'o', 'f', 'p', 's', 'k', 'v', 'y', 'i', 'w', 'u' };

vector<string> element2 = {
	"ba", "ca", "ga", "la", "na", "pa", "ra", "ta", "db", "nb", "pb", "rb", "sb", "tb", "yb", "ac",
	"sc", "tc", "cd", "gd", "md", "nd", "pd", "be", "ce", "fe", "ge", "he", "ne", "re", "se", "te",
	"xe", "cf", "hf", "rf", "ag", "hg", "mg", "rg", "sg", "bh", "rh", "th", "bi", "li", "ni", "si",
	"ti", "bk", "al", "cl", "fl", "tl", "am", "cm", "fm", "pm", "sm", "tm", "cn", "in", "mn", "rn",
	"sn", "zn", "co", "ho", "mo", "no", "po", "np", "ar", "br", "cr", "er", "fr", "ir", "kr", "lr",
	"pr", "sr", "zr", "as", "cs", "ds", "es", "hs", "os", "at", "mt", "pt", "au", "cu", "eu", "lu",
	"pu", "ru", "lv", "dy"
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    string word;
    vector<vector<bool>> is_element(26, vector<bool>(27, false));

    // 두 번째 차원의 24번째를 ""로 생각하기
    // 즉, 한 자리인지 판단할 때 사용
    for(int i=0; i < element1.size(); i++) {
        is_element[element1[i] - 'a'][26] = true;
    }

    for(int i=0; i < element2.size(); i++) {
        is_element[element2[i][0] - 'a'][element2[i][1] - 'a'] = true;
    }

    while(T--) {
        cin >> word;

        vector<bool> dp(word.size() + 1, false);

        dp[0] = true;

        for(int i=0; i < word.size(); i++) {
            if(dp[i] == false) {
                continue;
            }

            if(is_element[word[i] - 'a'][26]) {
                dp[i + 1] = true;
            }
            if(i + 1 < word.size() && is_element[word[i] - 'a'][word[i + 1] - 'a']) {
                dp[i + 2] = true;
            }

            if(dp[i + 1] == false && dp[i + 2] == false) {
                break;
            }
        }

        if(dp[word.size()]) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}