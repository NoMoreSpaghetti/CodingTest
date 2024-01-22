#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int N;

vector<pair<int, int>> lines;
vector<int> ans;
// {A에 있는 전깃줄 위치, lis에서의 위치} 저장
vector<pair<int, int>> idxes;

int binary_search(int left, int right, int val) {
    int mid;
    while(left < right) {
        mid = (left + right) / 2;
        if(ans[mid] < val) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return right;
}

int lis() {
    int ans_idx = 0;
    for(int i=1; i < N; i++) {
        if(ans[ans_idx] < lines[i].second) {
            ans[++ans_idx] = lines[i].second;
            idxes[i] = {lines[i].first, ans_idx};
        } else {
            int idx = binary_search(0, ans_idx, lines[i].second);
            ans[idx] = lines[i].second;
            idxes[i] = {lines[i].first, idx};
        }
    }
    return ans_idx + 1;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.first > b.first) {
        return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B;
    cin >> N;

    ans = vector<int>(N, -1);
    idxes = vector<pair<int, int>>(N, {-1, -1});

    for(int i=0; i < N; i++) {
        cin >> A >> B;
        lines.push_back({A, B});
    }

    sort(lines.begin(), lines.end(), cmp);

    ans[0] = lines[0].second;
    idxes[0] = {lines[0].first, 0};

    int lis_len = lis();
    cout << N - lis_len << '\n';
    stack<int> s;

    sort(idxes.begin(), idxes.end(), cmp);

    // lis는 하나씩 증가
    // 입력 순서를 거꾸로 했을 때, 마지막 위치에 해당하면 lis에 포함된 원소
    // 마지막 위치에 해당하지 않을 경우 lis에 포함되지 않은 원소
    lis_len--;
    for(int i=N - 1; i >= 0; i--) {
        // lis에서의 위치가 마지막이면
        // 해당 원소는 lis에 포함된 원소로 판단.
        // lis의 길이 줄이기
        if(idxes[i].second == lis_len) {
            lis_len--;
        // 그렇지 않으면
        // lis에 포함되지 않음
        } else {
            s.push(idxes[i].first);
        }
    }

    while(!s.empty()) {
        cout << s.top() << '\n';
        s.pop();
    }
}