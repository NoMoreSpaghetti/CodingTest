#include <iostream>
#include <vector>
using namespace std;

int N;

void floyd_warshall(vector<vector<int>>& friends) {
    for(int k=0; k < N; k++) {
        for(int i=0; i < N; i++) {
            for(int j=0; j < N; j++) {
                // friends[i][j]가 1000인 경우
                // i와 k가 친구이고 k와 j가 친구이면 friends[i][j]에 1+1 저장
                if(friends[i][j] > friends[i][k] + friends[k][j]) {
                    friends[i][j] = friends[i][k] + friends[k][j];
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    string inp;
    vector<vector<int>> friends(N, vector<int>(N, 1000));
    for(int i=0; i < N; i++) {
        cin >> inp;
        friends[i][i] = 0;
        for(int j=i + 1; j < N; j++) {
            if(inp[j] == 'Y') {
                friends[i][j] = 1;
                friends[j][i] = 1;
            }
        }
    }

    floyd_warshall(friends);

    int max_num_2_friends = 0;
    for(int i=0; i < N; i++) {
        int num_2_friends = 0;
        for(int j=0; j < N; j++) {
            if(i == j) {
                continue;
            }

            // 길이가 2보다 작은 경우:
            // i와 j가 친구일 때
            // i와 j가 2-친구일 때
            // 2보다 큰 경우는 1000밖에 없음
            if(friends[i][j] != 0 && friends[i][j] <= 2) {
                num_2_friends++;
            }
        }
        if(num_2_friends > max_num_2_friends) {
            max_num_2_friends = num_2_friends;
        }
    }

    cout << max_num_2_friends << '\n';
}