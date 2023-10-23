#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, inp;
    cin >> N;
    stack<int> s;
    stack<int> s2;
    vector<int> answers(N, -1);

    for(int i=0; i < N; i++) {
        cin >> inp;
        s.push(inp);
    }

    int answers_idx = N - 2;
    while(answers_idx >= 0) {
        int next = s.top();
        s.pop();

        if(next > s.top()) {
            // 다음 값이 현재 위치 값보다 크면;
            answers[answers_idx] = next;
            s2.push(next);
        } else {
            // 다음 값이 현재 위치 값보다 작으면
            // prev ><? cur > next
            // prev에서도 next를 고려할 이유가 없다.
            // s2에서 값을 꺼내서 더 큰 값이 있는지 확인해야함
            // 꺼내는 과정에서 cur보다 작은 값을 꺼내면 다시 넣을 필요 없음
            while(!s2.empty()) {
                next = s2.top();
                s2.pop();
                if(next > s.top()) {
                    answers[answers_idx] = next;
                    s2.push(next);
                    break;
                }
            }
        }
        answers_idx--;
    }

    for(auto& element : answers) {
        cout << element << ' ';
    }
}