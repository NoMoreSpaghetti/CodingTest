#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int get_gcd(int a, int b) {
    int c;
    while(b != 0) {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string inp;
    getline(cin, inp);
    N = stoi(inp);

    while(N--) {
        
        getline(cin, inp);

        stringstream ss(inp);
        ss.str(inp);

        string num_str;
        vector<int> nums;
        while(getline(ss, num_str, ' ')) {
            int num = stoi(num_str);
            nums.push_back(num);
        }

        int max_gcd = 0;
        for(int i=0; i < nums.size(); i++) {
            for(int j=i + 1; j < nums.size(); j++) {
                max_gcd = max(max_gcd, get_gcd(nums[i], nums[j]));
            }
        }

        cout << max_gcd << '\n';
    }
}