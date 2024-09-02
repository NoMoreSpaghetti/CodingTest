#include <iostream>
#include <vector>
using namespace std;

// '조작'이 왼쪽부터 순서대로야 한다는 말이 없음에도 불구하고
// 왼쪽부터 순서대로 정렬해야 정답처리
// 다음 예시는 최적의 정답과 다른 출력이 나온다.
// input: 5
// 2 5 3 1 4
// 최적: 
// 3
// 2 4
// 1 2
// 4 5
// 출력(정답):
// 4
// 1 4
// 2 4
// 3 4
// 4 5

vector<int> A;

void reverse(int start, int end) {
    while(start < end) {
        swap(A[start++], A[end--]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    A = vector<int>(N + 1, 0);

    for(int i=1; i <= N; i++) {
        cin >> A[i];
    }

    int ans = 0;
    vector<pair<int, int>> convert_vec;

    int start = 1;
    while(start < N && A[start] == start) {
        start++;
    }

    while(start < N) {
        for(int i=start + 1; i <= N; i++) {
            if(A[i] == start) {
                ans++;
                convert_vec.push_back({start, i});
                reverse(start, i);
                break;
            }
        }
        start++;
    }

    if(ans > 100) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
        for(const pair<int, int>& convert_pair: convert_vec) {
            cout << convert_pair.first << ' ' << convert_pair.second << '\n';
        }
    }
}