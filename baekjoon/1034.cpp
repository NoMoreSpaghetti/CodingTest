#include <iostream>
#include <vector>
#include <map>
using namespace std;

int count_0(string num_str) {
    int num = 0;
    for(char& c: num_str) {
        if(c == '0') {
            num++;
        }
    }
    return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K, max_num = 0;
    map<string, int> lamps;
    cin >> N >> M;

    string inp;

    for(int i=0; i < N; i++) {
        cin >> inp;
        lamps[inp]++;
    }

    cin >> K;

    for(auto& element: lamps) {
        // K 가 0의 개수보다 많아야 하고
        // 0의 개수가 짝수이면 K도 짝수여야 한다
        // 0의 개수가 홀수이면 K도 홀수여야 한다.
        int num_0 = count_0(element.first);
        if(num_0 <= K && ((num_0 & 1) == (K & 1)) && element.second > max_num) {
            max_num = element.second;
        }
    }

    cout << max_num << '\n';
}