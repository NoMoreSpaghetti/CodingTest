#include <iostream>
using namespace std;

class Node {
    public:
        Node() 
            : end_of_number(false)
            , has_child(false)
        {
        }

        ~Node() {
            for(int i=0; i < 10; i++) {
                if(nodes_[i]) {
                    delete nodes_[i];
                }
            }
        }

        Node* get_child(int num) {
            return nodes_[num];
        }

        void add_child(int num) {
            nodes_[num] = new Node();
            has_child = true;
        }

        bool end_of_number;
        bool has_child;

    private:
        Node* nodes_[10] = {};
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    string inp;
    cin >> t;

    while(t--) {
        cin >> n;
        Node root = Node();
        bool consistency = true;
        for(int i=0; i < n; i++) {
            cin >> inp;
            if(consistency) {
                Node* cur_node = &root;
                Node* next_node;
                int j=0;
                for(; j < inp.length() - 1; j++) {
                    next_node = cur_node->get_child(inp[j] - '0');
                    if(next_node == nullptr) {
                        cur_node->add_child(inp[j] - '0');
                        cur_node = cur_node->get_child(inp[j] - '0');
                    } else {
                        cur_node = next_node;
                        if(cur_node->end_of_number) {
                            consistency = false;
                            break;
                        }
                    }
                }
                // 마지막 글자일 때 nullptr이 아니면 일관성이 없다.
                next_node = cur_node->get_child(inp[j] - '0');
                if(next_node == nullptr) {
                    cur_node->add_child(inp[j] - '0');
                    next_node = cur_node->get_child(inp[j] - '0');
                    next_node->end_of_number = true;
                } else {
                    if(next_node->has_child) {
                        consistency = false;
                    } else {
                        next_node->end_of_number = true;
                    }
                }
            }
        }
        string return_str = (consistency) ? "YES" : "NO";
        cout << return_str << '\n';
    }
}