#include <iostream>
#include <ctime>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    struct tm* t;
    time_t timer = time(NULL);
    // UTC+0을 UTC+9에 맞추기
    timer += 9 * 60 * 60;
    t = localtime(&timer);
    
    cout << t->tm_year + 1900 << '-';
    cout.width(2);
    cout.fill('0');
    cout << t->tm_mon + 1 << '-';
    cout.width(2);
    cout.fill('0');
    cout << t->tm_mday;
}