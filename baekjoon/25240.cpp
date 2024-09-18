#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <sstream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int U, F, Q;
    string inp, user_name, user_group, file_name, file_permission, owner, owned_group;
    char op;
    cin >> U >> F;
    cin.ignore();

    unordered_map<string, unordered_set<string>> users;
    map<char, int> op_map = {{'R', 4}, {'W', 2}, {'X', 1}};
    unordered_map<string, vector<string>> files;


    for(int i=0; i < U; i++) {
        vector<string> user_inputs;
        
        getline(cin, inp);
        stringstream ss(inp);
        string str_buf;
        while(getline(ss, str_buf, ' ')) {
            user_inputs.push_back(str_buf);
        }

        if(user_inputs.size() > 1) {
            users[user_inputs[0]].insert(user_inputs[0]);
            stringstream ss2(user_inputs[1]);
            while(getline(ss2, str_buf, ',')) {
                users[user_inputs[0]].insert(str_buf);
            }
        } else {
            users[user_inputs[0]].insert(user_inputs[0]);
        }
    }

    for(int i=0; i < F; i++) {
        cin >> file_name >> file_permission >> owner >> owned_group;
        files[file_name] = {file_permission, owner, owned_group};
    }

    cin >> Q;
    for(int i=0; i < Q; i++) {
        cin >> user_name >> file_name >> op;
        int op_bit = op_map[op];
        unordered_set<string>& groups = users[user_name];

        vector<string>& file_info = files[file_name];

        int permission_idx = 2;

        // user가 OWNER인 경우
        if(file_info[1] == user_name) {
            permission_idx = 0;
        } else if (groups.find(file_info[2]) != groups.end()) {
            // user가 GROUP인 경우
            permission_idx = 1;
        }
        if((file_info[0][permission_idx] - '0' & op_bit) == op_bit) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}