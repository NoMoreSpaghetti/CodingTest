#include <iostream>
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

int get_lcm(int a, int b) {
    return (a * b) / get_gcd(a, b);
}

class fraction {
public:
    fraction(int numerator, int denominator)
    : numerator(numerator), denominator(denominator)
    {
    }

    void operator+=(fraction& target) {
        int lcm = get_lcm(denominator, target.get_denominator());

        numerator *= lcm / denominator;
        numerator += target.get_numerator() * (lcm / target.get_denominator());
        denominator = lcm;
        reduction();
    }

    void reduction() {
        int gcd = get_gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

    void print() {
        cout << numerator << ' ' << denominator << '\n';
    }

    int get_numerator() {
        return numerator;
    }

    int get_denominator() {
        return denominator;
    }

private:
    int numerator;
    int denominator;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B;
    cin >> A >> B;
    fraction f_1(A, B);
    cin >> A >> B;
    fraction f_2(A, B);

    f_1 += f_2;
    f_1.print();
}