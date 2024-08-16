#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long D, N, M ,K;
    cin >> D >> N >> M >> K;

    long long num_MD = N / D + M / D;
    long long ans = 0;

    // D개를 한 세트라고 생각하기
    // 짜장과 짬뽕은 세트를 제외한 양으로 생각하기
    N %= D;
    M %= D;

    // 볶음밥을 주문. 한 세트 모자라게 주문
    if(K / D >= 2) {
        ans += (K / D - 1) * D;
        K = K % D + D;
    }

    // 짜장면과 짬뽕 중 양이 많은 쪽을 짜장으로 생각하기
    if(M > N) {
        swap(N, M);
    }

    if(K >= (D - N) + (D - M) + D) {
    // 짜장, 짬뽕, 볶음밥을 모두 세트로 완성할 수 있으면 완성하기
        K -= (D - N) + (D - M) + D;
        ans += D;
    } else if(K >= (D - N) + D) {
    // 짜장과 볶음밥을 각각 세트로 완성할 수 있으면 완성하기
        K -= (D - N) + D;
        ans += D;
    } else if(K >= (D - N) + (D - M)) {
        // K명이 짬뽕과 짜장을 각각 세트로 완성할 수 있으면 완성하기
        K -= (D - N) + (D - M);
    }

    // 남은 K명은 모두 볶음밥을 시키기
    ans += K;

    cout << ans << '\n';
}