#include <iostream>
#include <vector>
using namespace std;

int N;
const string question_s1 = "\"재귀함수가 뭔가요?\"";
const string recursive_s1 = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.";
const string recursive_s2 = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.";
const string recursive_s3 = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"";
const string end_s = "\"재귀함수는 자기 자신을 호출하는 함수라네\"";
const string recursive_end_s = "라고 답변하였지.";
const string indent_s = "____";

vector<string> recursive_strings = {question_s1, recursive_s1, recursive_s2, recursive_s3};
vector<string> end_strings = {question_s1, end_s, recursive_end_s};

void print_indent(int n) {
    for(int i=0; i < n; i++) {
        cout << indent_s;
    }
}

void recursive_func(int n) {
    if(n == N) {
        for(const string& s: end_strings) {
            print_indent(n);
            cout << s << '\n';
        }
        return;
    }

    for(const string& s: recursive_strings) {
        print_indent(n);
        cout << s << '\n';
    }

    recursive_func(n + 1);

    print_indent(n);
    cout << recursive_end_s << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << '\n';
    recursive_func(0);
}