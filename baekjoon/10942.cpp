#include <iostream>
using namespace std;

int N, M, S, E;
int ary[2001];
int is_p[2001][2001];

bool is_palindrome(int s, int e) {
    if(e - s <= 0) {
        return true;
    } else if(is_p[s][e] != -1) {
        return is_p[s][e];
    } else {
        is_p[s][e] = is_palindrome(s + 1, e - 1) && (ary[s] == ary[e]);
        return is_p[s][e];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&is_p[0][0], &is_p[2000][2001], -1);

    cin >> N;
    for(int i=1; i <= N; i++) {
        cin >> ary[i];
    }
    cin >> M;
    for(int i=0; i < M; i++) {
        cin >> S >> E;
        if(is_palindrome(S, E)) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}