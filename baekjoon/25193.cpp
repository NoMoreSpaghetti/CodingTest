#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string s;
    cin >> N >> s;

    int num_c = 0;
    for(const auto& c: s) {
        if(c == 'C') {
            num_c++;
        }
    }

    int num_not_c = N - num_c;
    int ans = num_c / (num_not_c + 1);
    if(num_not_c > 0 && num_c % (num_not_c + 1) > 0) {
        ans++;
    }

    cout << ans << '\n';
}