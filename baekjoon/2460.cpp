#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num_get_off;
    int num_get_on;
    int num_people = 0;
    int ans = 0;

    for(int i=0; i < 10; i++) {
        cin >> num_get_off >> num_get_on;
        num_people += num_get_on - num_get_off;
        ans = max(ans, num_people);
    }
    cout << ans << '\n';
}