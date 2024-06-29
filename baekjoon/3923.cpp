#include <iostream>
#include <vector>
using namespace std;

void solution(int a, int b, int d) {
    int ans_num_a = 50000;
    int ans_num_b = 50000;

    auto update = [&](int num_a, int num_b) {
        if(num_a + num_b < ans_num_a + ans_num_b || (num_a + num_b == ans_num_a + ans_num_b && num_a * a + num_b * b < ans_num_a * a + ans_num_b * b)) {
            ans_num_a = num_a;
            ans_num_b = num_b;
        }
    };

    for(int i=-50000; i <= 50000; i++) {
        if((d - a * i) % b == 0) {
            int j = (d - a * i) / b;

            update(abs(i), abs(j));
        }
    }

    
    cout << ans_num_a << ' ' << ans_num_b << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int a, b, d;

    while(true) {
        cin >> a >> b >> d;
        if(a == 0 && b == 0 && d == 0) {
            break;
        }

        solution(a, b, d);
    }
}