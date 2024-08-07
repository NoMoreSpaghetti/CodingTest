#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> sorted;
vector<int> answer;
int num_converted = 0;

void merge(vector<int>& vec, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int t = left;
    while(i <= mid && j <= right) {
        if(vec[i] <= vec[j]) {
            sorted[t++] = vec[i++];
        } else {
            sorted[t++] = vec[j++];
        }
    }

    while(i <= mid) {
        sorted[t++] = vec[i++];
    }
    while(j <= right) {
        sorted[t++] = vec[j++];
    }

    for(i=left; i <= right; i++) {
        if(num_converted == K) {
            for(int j=0; j < N; j++) {
                answer[j] = vec[j];
            }
        }
        num_converted++;
        vec[i] = sorted[i];
    }
}


void merge_sort(vector<int>& vec, int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        merge_sort(vec, left, mid);
        merge_sort(vec, mid + 1, right);
        merge(vec, left, mid, right);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;

    vector<int> vec(N, 0);
    sorted = vector<int>(N, 0);
    answer = vector<int>(N, 0);

    for(int i=0; i < N; i++) {
        cin >> vec[i];
    }

    merge_sort(vec, 0, N - 1);

    if(num_converted < K) {
        cout << -1 << '\n';
    } else {
        for(int i=0; i < N; i++) {
            cout << answer[i] << ' ';
        }
        cout << '\n';
    }
}   