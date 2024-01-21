#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, K;
vector<int> selected_cards;
vector<int> roots;

int find_root(int n) {
    if(roots[n] == n) {
        return n;
    }
    return roots[n] = find_root(roots[n]);
}

void my_union(int x, int y) {
    if(roots[x] == roots[y]) {
        return;
    }
    roots[x] = roots[y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    int input;

    selected_cards = vector<int>(M, 0);
    roots = vector<int>(M, 0);

    for(int i=0; i < M; i++) {
        cin >> selected_cards[i];
        roots[i] = i;
    }

    sort(selected_cards.begin(), selected_cards.end());

    for(int i=0; i < K; i++) {
        cin >> input;
        int card_idx = find_root(upper_bound(selected_cards.begin(), selected_cards.end(), input) - selected_cards.begin());
        cout << selected_cards[card_idx] << '\n';
        my_union(card_idx, card_idx + 1);
    }
}