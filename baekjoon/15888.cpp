#include <iostream>
#include <vector>
using namespace std;

string solve(int A, int B, int C) {
    if(B * B - 4 * A * C < 0) { // 근이 허수인 경우
        return "둘다틀렸근";
    }

    vector<int> solutions;

    for(int i=-100; i <= 100; i++) {
        if(A * i * i + B * i + C == 0) {
            solutions.push_back(i);
        }
    }

    if(solutions.size() <= 1) { // 중근인 경우
        return "둘다틀렸근";
    }

    for(const auto& solution: solutions) {
        if(solution > 1) {
            int j = solution;
            while(j % 2 == 0) {
                j >>= 1;
            }
            if(j != 1) {
                return "정수근";
            }
        } else {
            return "정수근";
        }
    }

    return "이수근";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, C;
    cin >> A >> B >> C;

    cout << solve(A, B, C) << '\n';
}