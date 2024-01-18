#include <iostream>
#include <vector>
using namespace std;

int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    vector<int> lectures = vector<int>(N, 0);
    int max_lecture_len = 0;
    for(int i=0; i < N; i++) {
        cin >> lectures[i];
        max_lecture_len = max(max_lecture_len, lectures[i]);
    }

    int low = max_lecture_len, high = 1000000000;
    int mid, sum_of_lecture_len = 0, num_blurays = 0;

    while(low < high) {
        mid = (low + high) / 2;
        sum_of_lecture_len = 0;
        num_blurays = 1;
        for(int i=0; i < N; i++) {
            if(sum_of_lecture_len + lectures[i] > mid) {
                sum_of_lecture_len = lectures[i];
                num_blurays++;
            } else {
                sum_of_lecture_len += lectures[i];
            }
        }

        if(num_blurays > M) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    cout << high << '\n';
}