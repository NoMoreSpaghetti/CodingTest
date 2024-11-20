#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    int N, X;

    for(int t=1; t <= T; t++) {
        cin >> N >> X;
        vector<int> sizes(N, 0);

        for(int i=0; i < N; i++) {
            cin >> sizes[i];
        }

        sort(sizes.begin(), sizes.end());

        int left = 0;
        int right = N - 1;

        int y = 0;
        int sum = 0;

        while(left <= right) {
            sum += sizes[right];
            if(left < right && sum + sizes[left] <= X) {
                sum += sizes[left++];
            }
            y++;
            right--;
            sum = 0;
        }

        cout << "case #" << t << ": " << y << '\n';
    }
}