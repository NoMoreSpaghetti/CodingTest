#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    vector<char> vec;
    int sum = 0;
    cin >> s;

    for(int i=0; i < s.length(); i++) {
        vec.push_back(s[i]);
        sum += s[i] - '0';
    }

    sort(vec.begin(), vec.end(), greater<int>());

    if(vec.front() != '0' && vec.back() == '0' && sum % 3 == 0) {
        for(int i=0; i < vec.size(); i++) {
            cout << vec[i];
        }
    } else {
        cout << -1 << '\n';
    }
}