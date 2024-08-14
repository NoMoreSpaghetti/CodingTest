#include <iostream>
#include <stack>
using namespace std;

int convert(int d_num, int d) {
    int n = 0;
    int mul_d = 1;
    while(d_num) {
        n += (d_num % 10) * mul_d;
        d_num /= 10;
        mul_d *= d;
    }
    return n;
}

int dfs(int N, int d) {
    stack<pair<int, int>> s;
    int full_bit = (1 << d) - 1;
    
    // stack이므로 거꾸로
    for(int start_num=d - 1; start_num > 0; start_num--) {
        s.push({start_num, (1 << start_num)});
    }

    while(!s.empty()) {
        int num = s.top().first;
        int bit = s.top().second;
        s.pop();

        if(bit == full_bit) {
            int converted_num = convert(num, d);
            if(converted_num > N) {
                return converted_num;
            }
        } else {
            for(int i=d - 1; i >= 0; i--) {
                if(~bit & (1 << i)) {
                    s.push({num * 10 + i, bit | (1 << i)});
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, d;

    cin >> N >> d;

    cout << dfs(N, d) << '\n';
       
}