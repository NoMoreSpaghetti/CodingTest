#include <iostream>
#include <vector>
using namespace std;

string s;
int N;
vector<vector<bool>> dp;

bool CheckValid(int start, int end) {
    int left = start;
    int right = end;

    while(left < right) {
        if(s[left++] == s[right--]) {
            return false;
        }
    }
    return true;
}

// long long Solution(int idx) {
//     if(s[idx] != ')') {
//         return 0;
//     }

//     long long return_val = 0;

//     for(int i=idx - 1; i >= 0; i -= 2) {
//         if(s[i] != '(') continue;

//         // () 또는 (S)인지 검사
//         // 괄호 안이 편안한 문자열인지 검사
//         if(i == idx - 1 || dp[i + 1][idx - 1]) {
//             dp[i][idx] = true;
//             return_val++;
//         }

//         // S + T에 해당하는지 검사
//         for(int j=i + 1; j < idx; j++) {
//             if(dp[i][j] && dp[j + 1][idx]) {
//                 dp[i][idx] = true;
//                 return_val++;
//                 break;
//             }
//         }
//     }

//     return return_val;
// }

long long Solution() {
    long long return_val = 0;

    // 대칭 확인하기
    for(int i=N - 2; i >= 0; i--) {
        // 처음 두 개의 괄호 검사
        if(s[i] != s[i + 1]) {
            dp[i][i + 1] = true;
        }

        for(int j=i + 2; j < N; j++) {
            if(s[i] != s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
            }
        }
    }

    // 올바른 문자열 확인하기
    for(int i=N - 2; i >= 0; i--) {
        if(s[i] != '(') continue;

        int bracket_score = 1;

        bracket_score += s[i + 1] == ')' ? -1 : 1;

        // "()" 인 경우
        if(bracket_score == 0) {
            return_val++;
        }

        for(int j=i + 2; j < N; j++) {
            bracket_score += s[j] == ')' ? -1 : 1;
            // 괄호 점수가 음수가 되는 경우
            if(bracket_score < 0) {
                break;
            } else if(bracket_score > 0) {
                continue;
            }

            // 맨 겉의 괄호를 제외하고 그 안이 대칭 문자열인지 확인하기
            if(dp[i][j]) {
                return_val++;
            }
        }
    }

    return return_val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    N = s.length();

    dp = vector<vector<bool>>(N, vector<bool>(N, false));

    cout << Solution() << '\n';
}