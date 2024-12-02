#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, a, b;
    cin >> N;
    vector<int> switches(N, 0);

    for(int i=0; i < N; i++) {
        cin >> switches[i];
    }

    cin >> M;
    for(int i=0; i < M; i++) {
        cin >> a >> b;
        if(a == 1) {
            //남학생
            for(int j=b - 1; j < N; j += b) {
                switches[j] = !switches[j];
            }
        } else {
            // 여학생
            int left = b - 1;
            int right = b - 1;

            while(left - 1 >= 0 && right + 1 < N) {
                left--;
                right++;
                if(switches[left] != switches[right]) {
                    left++;
                    right--;
                    break;
                }
            }

            for(int j=left; j <= right; j++) {
                switches[j] = !switches[j];
            }
        }
    }

    for(int i=0; i < N; i++) {
        cout << switches[i] << ' ';
        if((i + 1) % 20 == 0) {
            cout << '\n';
        }
    }
}