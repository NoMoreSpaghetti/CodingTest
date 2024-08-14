#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;

LL get_amount(LL N, pair<LL, LL> cheaper,  pair<LL, LL> expensive_one) {
    LL ans = __LONG_LONG_MAX__;
    LL money;

    // i: 비싼 집에서 얼마나 살 것인가
    for(int i=0; i < cheaper.first; i++) {
        // 싼 집에서 얼마나 살 것인가
        LL amount = (N - i * expensive_one.first) / cheaper.first;

        // 싼 집에서 살 양이 음수가 되는 경우
        if(amount < 0) {
            break;
        }

        money = amount * cheaper.second;
        money += i * expensive_one.second;

        if((N - amount * cheaper.first - i * expensive_one.first) > 0) {
            money += cheaper.second;
        }

        ans = min(ans, money);
    }

    // 비싼 걸로만 사는 경우
    money = (N / expensive_one.first) * expensive_one.second;
    if(N % expensive_one.first) {
        money += expensive_one.second;
    }

    ans = min(ans, money);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    LL N;
    pair<LL, LL> A, C;
    cin >> N >> A.first >> A.second >> C.first >> C.second;

    // 가성비 비교해서 가성비가 좋은 꽃집을 먼저 고려
    if(A.first * C.second < C.first * A.second) {
        swap(A.first, C.first);
        swap(A.second, C.second);
    }

    cout << get_amount(N, A, C) << '\n';
}