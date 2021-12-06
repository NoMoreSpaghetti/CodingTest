#include <iostream>
#include <vector>
#define NUM_V (8)
#define DIV_NUM (1000000007)
using namespace std;

// 정보과학관:      0
// 전산관:          1
// 미래관:          2
// 신양관:          3
// 한경직기념관:    4
// 진리관:          5
// 형남공학관:      6
// 학생회관:        7
typedef long long ll;
int D;
vector<vector<ll>> univ_mat = {{0, 1, 1, 0, 0, 0, 0, 0},
                               {1, 0, 1, 1, 0, 0, 0, 0},
                               {1, 1, 0, 1, 1, 0, 0, 0},
                               {0, 1, 1, 0, 1, 1, 0, 0},
                               {0, 0, 1, 1, 0, 1, 1, 0},
                               {0, 0, 0, 1, 1, 0, 0, 1},
                               {0, 0, 0, 0, 1, 0, 0, 1},
                               {0, 0, 0, 0, 0, 1, 1, 0}};

vector<vector<ll>> mul_matrix(vector<vector<ll>>& mat1, vector<vector<ll>>& mat2) {
    vector<vector<ll>> return_mat(NUM_V, vector<ll>(NUM_V));
    for(int i=0; i < NUM_V; i++) {
        for(int j=0; j < NUM_V; j++) {
            for(int k=0; k < NUM_V; k++) {
                return_mat[i][j] += (mat1[i][k] * mat2[k][j]);
                return_mat[i][j] %= DIV_NUM;
            }
        }
    }

    return return_mat;
}

vector<vector<ll>> pow_matrix(vector<vector<ll>>& inp_mat, int num) {
    vector<vector<ll>> mat(NUM_V, vector<ll>(NUM_V));
    vector<vector<ll>> pow_mat(NUM_V, vector<ll>(NUM_V));
    for(int i=0; i < NUM_V; i++) {
        mat[i][i] = 1;
        for(int j=0; j < NUM_V; j++) {
            pow_mat[i][j] = inp_mat[i][j];
        }
    }

    while(num > 0) {
        if(num & 1) {
            mat = mul_matrix(mat, pow_mat);
        }
        pow_mat = mul_matrix(pow_mat, pow_mat);
        num >>= 1;
    }

    return mat;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> D;

    vector<vector<ll>> return_mat = pow_matrix(univ_mat, D);
    
    cout << return_mat[0][0] << '\n';
}