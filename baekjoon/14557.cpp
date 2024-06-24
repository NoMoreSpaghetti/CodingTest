#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int R, C;
    cin >> R >> C;


    // 해결하는데 필요한 가짓수
    int num_min_actions = R * C / 2;
    // 해결하는데 필요한 가짓수 + 2개를 남기고 다 까보는 횟수
    int num_max_actions = num_min_actions * 2 - 1;


    cout << num_min_actions << ' ' << num_max_actions << '\n';
}