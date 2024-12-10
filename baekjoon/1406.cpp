#include <iostream>
#include <list>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    int M;
    char op, inp;

    cin >> s >> M;

    list<char> s_list(s.begin(), s.end());

    list<char>::iterator cursor = s_list.end();

    for(int i=0; i < M; i++) {
        cin >> op;
        switch(op) {
            case 'L':
                if(cursor != s_list.begin()) cursor--;
                break;

            case 'D':
                if(cursor != s_list.end()) cursor++;
                break;

            case 'B':
                if(cursor == s_list.begin()) break;

                cursor--;
                cursor = s_list.erase(cursor);

                break;

            case 'P':
                cin >> inp;

                s_list.insert(cursor, inp);

                break;
        }
    }

    for(auto& iter: s_list) {
        cout << iter;
    }
    cout << '\n';
}