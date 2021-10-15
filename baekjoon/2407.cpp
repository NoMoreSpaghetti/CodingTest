#include <iostream>
using namespace std;

class big_int {
    public:
        long long u;
        long long d;

        big_int() {
            u = 0;
            d = 0;
        }

        big_int(long long u, long long d) {
            this->u = u;
            this->d = d;
        }

        big_int operator+(big_int &other) {
            long long temp = (this->d + other.d);
            long long d_sum_result = temp % 1000000000000000000;
            long long carry = temp / 1000000000000000000;
            long long u_sum_result = this->u + other.u + carry;
            
            return big_int(u_sum_result, d_sum_result);
        }

        void print() {
            if(u != 0) {
                cout << u << d << '\n';
            } else {
                cout << d << '\n';
            }
        }
};

big_int dp[101][101];

big_int calc(int n, int m) {
    for(int i=2; i <= n; i++) {
        for(int j=1; j <=i; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    return dp[n][m];
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i=0; i <= n; i++) {
        dp[i][0] = big_int(0, 1);
        dp[i][i] = big_int(0, 1);
    }

    big_int ans = calc(n, m);

    ans.print();
}