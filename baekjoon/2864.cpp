#include <iostream>
using namespace std;

int convert_5_to_6(int num) {
    return (num == 5) ? 6 : num;
}

int convert_6_to_5(int num) {
    return (num == 6) ? 5 : num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B;
    cin >> A >> B;

    int max_sum = 0, min_sum = 0;

    int digit = 1;
    while(A && B) {
        max_sum += digit * (convert_5_to_6(A % 10) + convert_5_to_6(B % 10));
        min_sum += digit * (convert_6_to_5(A % 10) + convert_6_to_5(B % 10));
        digit *= 10;
        A /= 10;
        B /= 10;
    }

    while(A) {
        max_sum += digit * convert_5_to_6(A % 10);
        digit *= 10;
    }

    while(B) {
        min_sum += digit * convert_6_to_5(B % 10);
        digit *= 10;
    }

    cout << min_sum << ' ' << max_sum << '\n';
}