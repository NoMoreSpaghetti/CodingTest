#include <iostream>
#include <vector>
using namespace std;

int alphabet_to_index(char alphabet) {
    return alphabet - 'a';
}

void floyd_washall(bool map[][26]) {
    for(int k=0; k < 26; k++) {
        for(int i=0; i < 26; i++) {
            for(int j=0; j < 26; j++) {
                if(map[i][k] && map[k][j]) {
                    map[i][j] = true;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    char a, b;
    string temp;
    bool map[26][26] = {0};

    cin >> n;
    for(int i=0; i < n; i++) {
        cin >> a >> temp >> b;

        int a_idx = alphabet_to_index(a);
        int b_idx = alphabet_to_index(b);

        map[a_idx][b_idx] = true;
    }

    floyd_washall(map);

    cin >> m;
    for(int i=0; i < m; i++) {
        cin >> a >> temp >> b;

        int a_idx = alphabet_to_index(a);
        int b_idx = alphabet_to_index(b);

        if(map[a_idx][b_idx]) {
            cout << "T" << '\n';
        } else {
            cout << "F" << '\n';
        }
    }
}