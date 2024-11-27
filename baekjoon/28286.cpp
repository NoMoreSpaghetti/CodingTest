// 참고: https://littlesam95.tistory.com/entry/BOJSilver-2-%EB%B0%B1%EC%A4%80-28286-%EC%9E%AC%EC%B1%84%EC%A0%90%EC%9D%84-%EA%B8%B0%EB%8B%A4%EB%A6%AC%EB%8A%94-%EC%A4%91C

#include <iostream>
#include <vector>
using namespace std;

int N, K;
int answer = 0;

vector<int> correct_answers;
vector<int> answers;

void DFS(int depth, vector<int> vec) {
    int correct_cnts = 0;
    for(int i=0; i < N; i++) {
        if(correct_answers[i] == vec[i]) {
            correct_cnts++;
        }
    }
    answer = max(answer, correct_cnts);

    if(depth >= K) {
        return;
    }

    for(int i=0; i < N; i++) {
        if(vec[i] > 0) {
            vector<int> new_vec(vec);
            // 당기기
            for(int j=i; j < N; j++) {
                new_vec[j] = new_vec[j + 1];
            }

            new_vec[N - 1] = 0;
            DFS(depth + 1, new_vec);

            // 초기화
            for(int j=i; j < N; j++) {
                new_vec[j] = vec[j];
            }

            // 밀기
            for(int j=N - 1; j > i; j--) {
                new_vec[j] = new_vec[j - 1];
            }
            new_vec[i] = 0;
            DFS(depth + 1, new_vec);
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;

    correct_answers = vector<int>(N, 0);
    answers = vector<int>(N, 0);
    
    for(int i=0; i < N; i++) {
        cin >> correct_answers[i];
    }

    for(int i=0; i < N; i++) {
        cin >> answers[i];
    }

    DFS(0, answers);
    cout << answer << '\n';
}