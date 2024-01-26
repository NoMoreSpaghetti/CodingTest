#include <iostream>
#include <vector>
#define DIV_NUM 10007
#define NUM_CARDS 52
using namespace std;

int N;
vector<vector<int>> bino;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    if(N < 4) {
        cout << 0 << '\n';
    } else {
        bino = vector<vector<int>>(NUM_CARDS + 1, vector<int>(NUM_CARDS + 1, 0));
        for(int i=0; i <= NUM_CARDS; i++) {
            bino[i][0] = 1;
            bino[i][i] = 1;
        }
        for(int i=1; i <= NUM_CARDS; i++) {
            for(int j=1; j <= NUM_CARDS; j++) {
                bino[i][j] = (bino[i - 1][j - 1] + bino[i - 1][j]) % DIV_NUM;
            }
        }

        int num_fourcards = N / 4;
        int ans = 0;
        for(int i=1; i <= num_fourcards; i++) {
            if(i % 2 == 0) {
                ans = (ans + DIV_NUM - (bino[13][i] * bino[NUM_CARDS - i * 4][N - i * 4]) % DIV_NUM) % DIV_NUM;
            } else {
                ans = (ans + bino[13][i] * bino[NUM_CARDS - i * 4][N - i * 4]) % DIV_NUM;
            }
        }
        cout << ans << '\n';
    }
}