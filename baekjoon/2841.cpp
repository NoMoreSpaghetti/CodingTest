#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, P, line_num, fret_num;
    cin >> N >> P;

    vector<priority_queue<int>> vec(P, priority_queue<int>());
    
    int num_move = 0;

    while(N--) {
        cin >> line_num >> fret_num;
        line_num--;

        while(!vec[line_num].empty() && vec[line_num].top() > fret_num) {
            num_move++;
            vec[line_num].pop();
        }

        if(vec[line_num].empty()) {
            num_move++;
            vec[line_num].push(fret_num);
        } else if(vec[line_num].top() != fret_num) {
            num_move++;
            vec[line_num].push(fret_num);
        }
    }

    cout << num_move << '\n';
}