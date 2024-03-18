#include <iostream>
#include <vector>
using namespace std;

int N;
const string question_s1 = "\"����Լ��� ������?\"";
const string recursive_s1 = "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.";
const string recursive_s2 = "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.";
const string recursive_s3 = "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"";
const string end_s = "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"";
const string recursive_end_s = "��� �亯�Ͽ���.";
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
    
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << '\n';
    recursive_func(0);
}