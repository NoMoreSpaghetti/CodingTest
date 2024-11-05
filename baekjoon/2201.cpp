#include <iostream>
#include <vector>
using namespace std;

long long K;
vector<long long> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;

    // index는 글자 수, 값은 해당 글자 수에 존재하는 이친수 개수
    dp.push_back(0);
    dp.push_back(1);

    if(K == 1) {
        cout << "1" << '\n';
        return 0;
    }

    long long sum = 1;
    long long cur_len = 2;

    // 피보나치 계산
    while(sum < K) {
        dp.push_back(dp[cur_len - 1] + dp[cur_len - 2]);
        sum += dp.back();
        cur_len++;
    }

    // 현재 길이에 해당하는 개수만큼 빼기
    cur_len--;
    sum -= dp[cur_len];
    K -= sum;
    string start_str = "10";


    // 0으로 끝나는 경우 추가하기
    sum++;

    // 11이 불가능하므로 현재 길이 - 1 에 해당하는 개수 빼기
    int prev_len = cur_len - 1;
    sum -= dp[prev_len];

    while(prev_len > 1) {
        prev_len--;
        sum -= dp[prev_len];

        
        if(K > sum) {
            K -= sum;
            if(prev_len <= 1) {
                start_str += "1";
            } else {
                start_str += "10";
                prev_len--;
                sum -= dp[prev_len];
            }
        } else {
            start_str += "0";
        }
        
    }
    
    cout << start_str << '\n';
}