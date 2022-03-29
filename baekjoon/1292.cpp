#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B;
    cin >> A >> B;
    int sum = 0;
    int num = 0;
    int i = 1;

    while(true) {
        num += i;
        if(A <= num) {
            break;
        }
        i++;
    }
    
    if(num >= B) {
        sum += i * (B - A + 1);
    } else {
        sum += i * (num - A + 1);
        i++;
        while(true) {
            num += i;
            if(num >= B) {
                sum += i * (B - (num - i));
                break;
            } else {
                sum += i * i;
            }
            i++;
        }
    }

    cout << sum << '\n';
}