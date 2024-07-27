#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B;
    cin >> A >> B;

    if(A <= B || A > 2 * B) {
        cout << "NO" << '\n';
    } else {
        int num_burgers = A - B;
        int num_big = B % num_burgers;
        int num_small = num_burgers - num_big;
        int small_burger_size = B / num_burgers;
        int big_burger_size = small_burger_size + 1;
        // num_big == 0이면 small burger size == big burger size. 그게 아니면 big burger size는 small burger size + 1
        cout << "YES" << '\n';
        cout << num_burgers << '\n';

        for(int i=0; i < num_small; i++) {
            for(int j=0; j < small_burger_size; j++) {
                cout << "ab";
            }
            cout << 'a' << '\n';
        }
        
        for(int i=0; i < num_big; i++) {
            for(int j=0; j < big_burger_size; j++) {
                cout << "ab";
            }
            cout << 'a' << '\n';
        }
    }
}