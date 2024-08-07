#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    string s, p;
    cin >> T;
    
    while(T--) {
        cin >> s >> p;
        int time = 0;
        for(int i=0; i < s.size(); i++) {
            int k=i;
            int j=0;
            while(j < p.size() && s[k] == p[j]) {
                k++;
                j++;
            }

            if(j == p.size()) {
                i = k - 1;
            }
            time++;
        }
        cout << time << '\n';
    }
}