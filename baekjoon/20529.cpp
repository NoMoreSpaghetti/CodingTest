#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, dist;
    string inp;
    string MBTIs[32];
    cin >> t;

    while(t--) {
        cin >> n;
        dist = 0;

        // n이 33 이상이면
        // 같은 mbti가 무조건 3개는 존재
        if(n > 32) {   
            for(int i=0; i < n; i++) {
                cin >> inp;
            }         
            cout << 0 << '\n';
        } else {
            for(int i=0; i < n; i++) {
                cin >> MBTIs[i];
            }

            int dists[32][32] = {0};

            // 2개 입력끼리 거리 미리 계산
            for(int i=0; i < n; i++) {
                for(int j=i + 1; j < n; j++) {
                    for(int k=0; k < 4; k++) {
                        dists[i][j] += MBTIs[i][k] != MBTIs[j][k];
                    }
                }
            }

            int min_dist = 8;

            for(int i=0; i < n; i++) {
                for(int j=i + 1; j < n; j++) {
                    for(int k=j + 1; k < n; k++) {
                        dist = dists[i][j] + dists[j][k] + dists[i][k];
                        if(dist < min_dist) {
                            min_dist = dist;
                        }
                    }
                }
            }

            cout << min_dist << '\n';
        }
    }
}