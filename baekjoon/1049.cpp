#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, x, y;
    int min_pack, min_single;

    cin >> N >> M;

    cin >> x >> y;
    min_pack = x;
    min_single = y;

    for(int i=1; i < M; i++) {
        cin >> x >> y;
        min_pack = min(min_pack, x);
        min_single = min(min_single, y);
    }

    
    int answer;

    if(6 * min_single > min_pack) {
        answer = (N / 6) * min_pack;
        if((N % 6) * min_single > min_pack) {
            answer += min_pack;
        } else {
            answer += (N % 6) * min_single;
        }
    } else {
        answer = N * min_single;
    }

    cout << answer << '\n';
}