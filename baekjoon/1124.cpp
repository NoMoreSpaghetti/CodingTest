#include <iostream>
#include <vector>
#define MAX (100001)
using namespace std;

int A, B;
vector<bool> prime;
vector<int> num_primes;

bool CheckUnderprime(int num) {
    int cnt = 0;
    int num_copy = num;

    for(long long i=2; i * i <= num_copy; i++) {
        while(num_copy % i == 0) {
            cnt++;
            num_copy /= i;
        }

        if(num_primes[num_copy] != -1) {
            cnt += num_primes[num_copy];
            num_copy = 1;
        }
    }

    if(num_copy > 1) cnt++;

    num_primes[num] = cnt;

    return prime[cnt];
}

void Eratosthenes() {
    prime[1] = false;

    for(long long i=2; i < B + 1; i++) {
        if(prime[i] == false) continue;

        for(long long j=i * i; j < B + 1; j += i) {
            prime[j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B;

    prime = vector<bool>(B + 1, true);
    num_primes = vector<int>(B + 1, -1);

    Eratosthenes();

    int ans = 0;
    for(int i=A; i <= B; i++) {
        if(CheckUnderprime(i)) {
            ans++;
        }
    }
    cout << ans << '\n';
}