#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(const string& a, const string& b) {
    if(a.length() < b.length()) {
        return true;
    } else if(a.length() > b.length()) {
        return false;
    } else {
        return a.compare(b) < 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<string>> students(N + 1, vector<string>());
    int class_num;
    string name;

    while(true) {
        cin >> class_num >> name;
        if(class_num == 0) {
            break;
        }
        if(students[class_num].size() < M) {
            students[class_num].push_back(name);
        }
    }
    

    for(int start_i=1; start_i <= 2; start_i++) {
        for(int i=start_i; i <= N; i+=2) {
            sort(students[i].begin(), students[i].end(), cmp);
            for(const auto& student : students[i]) {
                cout << i << ' ' << student << '\n';
            }
        }
    }
}