#include <iostream>
#include <vector>
using namespace std;

int pow(int num, int cnt) {
    int answer = num;
    for(int i=1; i < cnt; i++) {
        answer *= num;
    }
    return answer;
}

long long get_gcd(long long a, long long b) {
    long long c;
    while(b != 0) {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

bool comp(pair<int, int>& a, pair<int, int>& b) {
    if(((double)a.first / a.second) > ((double)b.first / b.second)) {
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> nums(M, vector<int>(3, 0));
    vector<int> counts(N + 1, 0);
    vector<pair<long long, long long>> probs(N + 1, {0, 0});

    for(int i=0; i < M; i++) {
        for(int j=0; j < 3; j++) {
            cin >> nums[i][j];
            counts[nums[i][j]]++;
        }
    }

    
    for(int i=1; i <= N; i++) {
        probs[i].first = counts[i];
        probs[i].second = 3 * M;
    }

    pair<long long, long long> max_prob = {0, 1};
    vector<int> answer(3, 0);

    for(int i=1; i <= N; i++) {
        for(int j=i + 1; j <= N; j++) {
            for(int k=j + 1; k <= N; k++) {

                // 세 숫자 중 하나가 뽑힐 확률
                pair<long long, long long> prob1 = {probs[i].first + probs[j].first + probs[k].first + 3, probs[k].second};

                // 세 숫자 모두 안 뽑힐 확률:
                pair<long long, long long> prob2 = {probs[k].second - prob1.first, probs[k].second};
                prob2.first = pow(prob2.first, K) * prob1.first;
                prob2.second = pow(prob2.second, K + 1);
                
                long long gcd = get_gcd(prob2.first, prob2.second);
                prob2.first /= gcd;
                prob2.second /= gcd;

                // 가장 높은 확률 저장
                if(comp(prob2, max_prob)) {
                    max_prob = prob2;
                    answer = {i, j, k};
                }
            }
        }
    }

    cout << max_prob.first << ' ' << max_prob.second << '\n';
    for(int i=0; i < 3; i++) {
        cout << answer[i] << ' ';
    }
}