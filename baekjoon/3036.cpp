#include <iostream>
#include <vector>
using namespace std;

int N;

int get_gcd(int a, int b) {
    int c;

    while(b != 0) {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    vector<int> vec(N, 0);

    for(int i=0; i < N; i++) {
        cin >> vec[i];
    }

    for(int i=1; i < N; i++) {
        int gcd = get_gcd(vec[0], vec[i]);
        cout << vec[0] / gcd << '/' << vec[i] / gcd << '\n';
    }
}