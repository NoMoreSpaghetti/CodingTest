#include <iostream>
#include <vector>
#include <queue>
#define SWAP(type, a, b) do{type temp = a; a = b; b = temp;} while(0);
using namespace std;

int N, K, m, v;
int C[300000];
int dp[300000];
priority_queue<pair<int, int>> jewels;
priority_queue<int> value_q;

int partition(int ary[], int left, int right) {
    int &p = ary[right];
    int low = left - 1;
    for(int high = left; high < right; high++) {
        if(ary[high] < p) {
            low++;
            SWAP(int, ary[low], ary[high]);
        }
    }
    SWAP(int, ary[low + 1], ary[right]);

    return low + 1;
}

void quick_sort(int ary[], int left, int right) {
    if(left < right) {
        int p = partition(ary, left, right);
        quick_sort(ary, left, p - 1);
        quick_sort(ary, p + 1, right);
    }
}

long long get_max_value() {
    long long value = 0;
    for(int i=0; i < K; i++) {
        while(!jewels.empty()) {
            pair<int, int> jewel = jewels.top();
            if(-jewel.first > C[i]) {
                break;
            } else {
                jewels.pop();
                value_q.push(jewel.second);
            }
        }

        if(!value_q.empty()) {
            value += value_q.top();
            value_q.pop();
        }
    }
    return value;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for(int n=0; n < N; n++) {
        cin >> m >> v;
        jewels.push({-m, v});
    }
    for(int k=0; k < K; k++) {
        cin >> C[k];
    }

    quick_sort(C, 0, K - 1);
    cout << get_max_value() << '\n';
}