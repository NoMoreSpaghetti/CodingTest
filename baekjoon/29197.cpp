#include <iostream>
#include <vector>
#include <set>
using namespace std;

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

    int N, x, y, gcd;
    cin >> N;
    set<pair<int, int>> positions;

    for(int i=0; i < N; i++) {
        cin >> x >> y;
        if(x == 0) {
            y /= abs(y);
        } else if(y == 0) {
            x /= abs(x);
        } else {
            gcd = abs(get_gcd(x, y));
            x /= gcd;
            y /= gcd;
        }
        positions.insert({x, y});
    }
    
    cout << positions.size();
}