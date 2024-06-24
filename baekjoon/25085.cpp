#include <iostream>
#include <vector>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    long long A;
    cin >> T;
    for(int t=0; t < T; t++) {
        vector<long long> factors;
        cin >> A;
        
        for(long long i=1; i * i <= A; i++) {
            if(A % i == 0) {
                factors.push_back(i);
                if(i * i != A) {
                    factors.push_back(A / i);
                }
            }
        }

        int num_pals = 0;
        for(auto& factor : factors) {
            if(factor < 10) {
                num_pals++;
            } else {
                string s = to_string(factor);
                int i=0;
                while(s[i] == s[s.length() - 1 - i] && i * 2 < s.length()) {
                    i++;
                }
                if(i * 2 >= s.length()) {
                    num_pals++;
                }
            }
        }

        cout << "Case #" << t + 1 << ": " << num_pals << '\n';

    }


}