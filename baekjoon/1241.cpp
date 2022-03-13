#include <iostream>
using namespace std;

int N;
int students[100001];
int nums[1000001] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0; i < N; i++) {
        cin >> students[i];
        nums[students[i]]++;
    }

    for(int i=0; i < N; i++) {
        int hit_num = 0;
        int j;
        for(j=1; j * j < students[i]; j++) {
            if(students[i] % j == 0) {
                hit_num += nums[j];
                hit_num += nums[students[i] / j];
            }
        }

        if(j * j == students[i]) {
            hit_num += nums[j];
        }

        cout << hit_num - 1 << '\n';
    }
}