#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Queue {
    public:
        Queue(int size)
            : queue(size + 1, 0)
            , max_size(size + 1)
            , front_idx(0)
            , rear_idx(0)
        {
        }
        void push(T element) {
            if(size() < max_size) {
                queue[rear_idx++] = element;
            }
        }
        T pop() {
            if(empty()) {
                return -1;
            }
            T return_val = queue[front_idx++];
            if(front_idx == max_size) {
                front_idx = 0;
            }
            return return_val;
        }
        int size() {
            return ((rear_idx + max_size) - front_idx) % max_size;
        }
        bool empty() {
            return rear_idx == front_idx;
        }
        int front() {
            if(empty()) {
                return -1;
            }
            return queue[front_idx];
        }
        int back() {
            if(empty()) {
                return -1;
            }
            return queue[(rear_idx == 0) ? queue[max_size - 1] :rear_idx - 1];
        }

    private:
        vector<T> queue;
        int max_size;
        int front_idx;
        int rear_idx;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, inp;
    string op;

    cin >> N;
    Queue<int> q(N);

    while(N--) {
        cin >> op;
        if(op == "push") {
            cin >> inp;
            q.push(inp);
        } else {
            if(op == "pop") {
                cout << q.pop();
            } else if(op == "size") {
                cout << q.size();
            } else if(op == "empty") {
                cout << q.empty() ? 1 : 0;
            } else if(op == "front") {
                cout << q.front();
            } else if(op == "back") {
                cout << q.back();
            }
            cout << '\n';
        }
    }
}