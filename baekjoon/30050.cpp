#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

typedef long long LL;

unordered_map<int, int> parents;

int find_p(int val) {
    if(parents.find(val) != parents.end()) {
        return parents[val];
    } else {
        return (val >> 1);
    }
}

LL query2(int a, int b) {
    LL sum = 0;
    sum += a + b;

    while(a != b) {
        if(a > b) {
            a = find_p(a);
            sum += a;
        } else { 
            b = find_p(b);
            sum += b;
        }
    }

    sum -= a;
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int Q, query_idx, a, b;
    cin >> Q;

    for(int i=0; i < Q; i++) {
        cin >> query_idx >> a >> b;
        if(query_idx == 1) {
            parents[b] = a;
        } else {
            cout << query2(a, b) << '\n';
        }
    }
}