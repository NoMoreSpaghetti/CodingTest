#include <iostream>
#include <deque>
using namespace std;

deque<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Q;
    char inp;
    string op;
    cin >> Q;
    
    // 0 1 2 3 == l u r d
    int direction = 0;
    int num_balls = 0;
    int num_walls = 0;

    while(Q--) {
        cin >> op;
        if(op == "pop") {
            if(!q.empty()) {
                if(q.front() == 1) {
                    num_balls--;
                    q.pop_front();
                } else {
                    num_walls--;
                    q.pop_front();
                    if(direction == 1) {
                        if(num_walls > 0) {
                            while(q.front() == 1) {
                                q.pop_front();
                                num_balls--;
                            }
                        } else {
                            num_balls = 0;
                            q.clear();
                        }
                    }
                }
            }
        } else {
            cin >> inp;
            if(op == "push") {
                if(inp == 'b') {
                    if(direction != 3 && !(direction == 1 && num_walls == 0)) {
                        q.push_back(1);
                        num_balls++;
                    }
                } else {
                    q.push_back(0);
                    num_walls++;
                }
            } else if(op == "rotate") {
                if(inp == 'l') {
                    direction = (direction - 1 + 4) % 4;
                } else {
                    direction = (direction + 1) % 4;
                }
                if(direction == 1) {
                    // 앞이 아래에 오게 된 경우
                    if(num_walls > 0) {
                        while(q.front() == 1) {
                            q.pop_front();
                            num_balls--;
                        }
                    } else {
                        num_balls = 0;
                        q.clear();
                    }
                } else if(direction == 3) {
                    if(num_walls > 0) {
                        while(q.back() == 1) {
                            q.pop_back();
                            num_balls--;
                        }
                    } else {
                        num_balls = 0;
                        q.clear();
                    }
                }

            } else if(op == "count") {
                if(inp == 'b') {
                    cout << num_balls << '\n';
                } else {
                    cout << num_walls << '\n';
                }
            }
        }
    }
}