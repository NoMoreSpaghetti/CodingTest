#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num_players = 8;
    vector<vector<double>> probabilities(num_players, vector<double>(num_players, -1));
    vector<double> ans(num_players, 0);

    for(int i=0; i < num_players; i++) {
        for(int j=i + 1; j < num_players; j++) {
            cin >> probabilities[i][j];
            probabilities[i][j] /= 100;
            probabilities[j][i] = 1 - probabilities[i][j];
        }
    }

    // 라운드 1
    for(int i=0; i < num_players; i+= 2) {
        ans[i] = probabilities[i][i + 1];
        ans[i + 1] = probabilities[i + 1][i];
    }

    // 라운드 2
    vector<double> copy(ans);
    ans = vector<double>(num_players, 0);
    for(int i=0; i < num_players; i++) {
        if(i / 2 % 2 == 0) {
            for(int j=(i / 2 + 1) * 2; j < (i / 2 + 1) * 2 + 2; j++) {
                ans[i] += copy[j] * probabilities[i][j];
            }
            ans[i] *= copy[i];
        } else {
            for(int j=(i / 2 - 1) * 2; j < (i / 2 - 1) * 2 + 2; j++) {
                ans[i] += copy[j] * probabilities[i][j];
            }
            ans[i] *= copy[i];
        }
    }

    copy = vector<double>(ans);
    ans = vector<double>(num_players, 0);
    // 라운드 3
    for(int i=0; i < num_players; i++) {
        if(i / 4 % 4 == 0) {
            for(int j=(i / 4 + 1) * 4; j < (i / 4 + 1) * 4 + 4; j++) {
                ans[i] += copy[j] * probabilities[i][j];
            }
            ans[i] *= copy[i];
        } else {
            for(int j=(i / 4 - 1) * 4; j < (i / 4 - 1) * 4 + 4; j++) {
                ans[i] += copy[j] * probabilities[i][j];
            }
            ans[i] *= copy[i];
        }
    }

    cout.precision(15);
    for(int i=0; i < num_players; i++) {
        cout << ans[i] << ' ';
    }
}