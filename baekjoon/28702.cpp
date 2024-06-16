#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> vec(3, "");
    cin >> vec[0] >> vec[1] >> vec[2];

    for(int i=0; i < vec.size(); i++) {
        try {
            int num = stoi(vec[i]) + 3 - i;
            if(num % 3 == 0 && num % 5 == 0) {
                cout << "FizzBuzz" << '\n';
            } else if(num % 3 == 0) {
                cout << "Fizz" << '\n';
            } else if(num % 5 == 0) {
                cout << "Buzz" << '\n';
            } else {
                cout << num << '\n';
            }

            break;
        } catch (invalid_argument& e) {
            continue;
        }
    }
}