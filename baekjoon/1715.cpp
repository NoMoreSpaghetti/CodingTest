#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, size;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> cards;

    for(int i=0; i < N; i++) {
        cin >> size;
        cards.push(size);
    }

    int answer = 0;
    while(cards.size() >= 2) {
        int a = cards.top();
        cards.pop();
        int b = cards.top();
        cards.pop();
        answer += a + b;
        cards.push(a + b);
    }

    cout << answer << '\n';
}