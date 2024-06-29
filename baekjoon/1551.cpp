#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    string inp;
    cin >> N >> K;
    cin >> inp;

    string num_str;
    string ans = inp;
    
    for(int i=0; i < K; i++) {
        int prev_num = 0;
        int idx = 1;
        stringstream ss(inp);
        ans = "";
        while(getline(ss, num_str, ',')) {
            if(idx != 1) {
                ans += to_string(stoi(num_str) - prev_num);
                if(idx < N - i) {
                    ans += ',';
                }
            }
            prev_num = stoi(num_str);
            idx++;
        }
        inp = ans;
    }

    cout << ans;

}