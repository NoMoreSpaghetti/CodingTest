#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long N;
    cin >> N;


    if(N % 2 == 0) {
        cout << "CY" << '\n';
    } else {
        cout << "SK" << '\n';
    }
}