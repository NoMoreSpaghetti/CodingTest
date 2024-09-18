#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, inp1, inp2, ans = 0;
    cin >> N;

    for(int i=0; i < N; i++) {
        cin >> inp1 >> inp2;
        ans += inp2 % inp1;
    }

    cout << ans << '\n';
}