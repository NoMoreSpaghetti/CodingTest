#include <iostream>
using namespace std;
int paper_num[2] = {0, };

void recursive(int **ary, int start_x, int start_y, int n) {
    int number_num[2] = {0, };
    bool all_same = true;
    
    if(n == 1) {
        paper_num[ary[start_x][start_y]]++;
        return;
    }
    
    int first_num = ary[start_x][start_y];
    for(int i=0; i < n; i++) {
        for(int j=0; j < n; j++) {
            if(ary[start_x + j][start_y + i] != first_num) {
                all_same = false;
                break;
            }
        }
    }
    
    if(all_same == true) {
        paper_num[first_num]++;
    }
    else {
        int new_n = n / 2;
        for(int i=0; i < 2; i++) {
            for(int j=0; j < 2; j++) {
                recursive(ary, start_x + new_n * j, start_y + new_n * i, new_n);
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    int **ary = new int*[N];
    
    for(int i=0; i < N; i++)
        ary[i] = new int[N];
    
    for(int i=0; i < N; i++)
        for(int j=0; j < N; j++)
            cin >> ary[i][j];
    
    recursive(ary, 0, 0, N);
    
    for(int i=0; i < 2; i++)
        cout << paper_num[i] << '\n';
    
    
    for(int i=0; i < N; i++)
        delete[] ary[i];
    delete[] ary;
}