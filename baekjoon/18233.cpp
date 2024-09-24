#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N, P, E;
vector<pair<int, int>> members;
vector<int> p_members;
vector<int> ans;

bool dfs(int idx, int p_num, int min_val, int max_val) {
    // idx번쨰 사람에게 나눠주기
    
    // P명이고 조건에 부합하면 정답 출력하고 종료
    if(p_num == P && min_val <= E && E <= max_val) {
        // p에 해당하는 사람들에게 최소개수씩 다 주고 시작
        int remain = E - min_val;

        for(int i=0; i < P; i++) {
            int gap = members[p_members[i]].second - members[p_members[i]].first;
            if(remain > gap) {
                ans[p_members[i]] = members[p_members[i]].first + gap;
                remain -= gap;
            } else {
                ans[p_members[i]] = members[p_members[i]].first + remain;
                remain = 0;
            }
        }
        return true;
    } else if(N - idx + p_num < P || idx >= N) {
        // 남은 사람 계산해서 P명을 채우지 못하면은 종료
        return false;
    } else {
        p_members.push_back(idx);
        if(dfs(idx + 1, p_num + 1, min_val + members[idx].first, max_val + members[idx].second)) {
            return true;
        }
        p_members.pop_back();
        return dfs(idx + 1, p_num, min_val, max_val);
    }
}

void solution() {
    if(dfs(0, 0, 0, 0)) {
        for(int i=0; i < N; i++) {
            cout << ans[i] << ' ';
        }
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y;
    cin >> N >> P >> E;
    members = vector<pair<int, int>>(N, {0, 0});
    ans = vector<int>(N, 0);

    for(int i=0; i < N; i++) {
        cin >> members[i].first >> members[i].second;
    }

    solution();
}