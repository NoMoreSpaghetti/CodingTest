#include <iostream>
#include <vector>
#include <map>
using namespace std;

char KSA[3] = {'K', 'S', 'A'};

int solution(string s, int start_idx) {
    // 제거 과정
    int idx = start_idx;
    int cnt = 0;
    for(int i=0; i < s.size(); i++) {
        if(s[i] != KSA[idx]) {
            cnt++;
        } else {
            idx = (idx + 1) % 3;
        }
    }

    // A로 시작하면 시작하는 A를 지워야 함
    // S로 시작하면 K를 추가하는 과정이 필요
    if(KSA[start_idx] == 'A' && cnt < 2) {
        // A로 시작하는데 2개 미만로 제거했으면
        // 앞에 KS를 추가할 수 없음.
        // A를 지워야 함
        cnt++;
    } else if(KSA[start_idx] == 'S' && cnt == 0) {
        // S로 시작하는데 이미 정렬되어 있는 경우
        // K를 추가하면 길이가 초과됨
        // K를 추가하고 맨 뒤를 제거
        // for문 바깥에서 추가 과정을 처리하므로 cnt 1만 증가
        cnt = 1;
    }

    // 추가 과정
    cnt *= 2;

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string X;
    cin >> X;

    int N = X.length();
    int ans = INT32_MAX;
    
    
    // 세 종류의 문자가 맨 처음일 때를 모두 비교
    for(int i=0; i < 3; i++) {
        ans = min(ans, solution(X, i));
    }

    cout << ans << '\n';
}