#include <iostream>
using namespace std;

int N;
int S[20];
bool available[2000001] = {0};

void recursive(int idx, int num) {
    if(idx > N) {
        return;
    } else {
        available[num] = true;
        recursive(idx + 1, num);
        recursive(idx + 1, num + S[idx]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int inp;
    cin >> N;
    for(int i=0; i < N; i++) {
        cin >> inp;
        S[i] = inp;
    }

    recursive(0, 0);

    for(int i=1; i < 2000001; i++) {
        if(!available[i]) {
            cout << i << '\n';
            break;
        }
    }
}