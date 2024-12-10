#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double ha, hb, hc;
    cin >> ha >> hb >> hc;

    double ha_pow4 = pow(ha, 4);
    double hb_pow4 = pow(hb, 4);
    double hc_pow4 = pow(hc, 4);

    double denominator = sqrt(2 * pow(ha * hb * hc, 2) * (ha * ha + hb * hb + hc * hc) - (ha_pow4 * hb_pow4 + ha_pow4 * hc_pow4 + hb_pow4 * hc_pow4));
    double numerator = pow(ha * hb * hc, 2);

    cout.precision(15);
    cout << numerator / denominator << '\n';
}