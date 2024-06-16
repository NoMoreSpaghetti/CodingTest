#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    string s;

    cin >> N >> K >> s;

    vector<char> st;
    st.push_back(s[0]);

    for(int i=1; i < N; i++) {
        while(K && !st.empty() && st.back() < s[i]) {
            st.pop_back();
            K--;
        }
        st.push_back(s[i]);
    }
    
    while(K) {
        st.pop_back();
        K--;
    }

    for(const auto& c: st) {
        cout << c;
    }
    cout << '\n';
}