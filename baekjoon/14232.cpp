#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long k, sqrt_k;
    cin >> k;
    sqrt_k = sqrtl(k);
    vector<long long> vec;

    while(k % 2 == 0) {
        vec.push_back(2);
        k >>= 1;
    }

    for(long long i=3; i <= sqrt_k; i += 2) {
        while(k % i == 0) {
            vec.push_back(i);
            k /= i;
            sqrt_k = sqrtl(k);
        }
    }
    if(k != 1) {
        vec.push_back(k);
    }

    cout << vec.size() << '\n';
    for(long long& element: vec) {
        cout << element << ' ';
    }
}