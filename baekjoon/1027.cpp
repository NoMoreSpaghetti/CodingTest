#include <iostream>
#include <vector>
#include <limits.h>
#include <float.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, inp, ans = 0;
    cin >> N;

    vector<int> buildings;
    

    for(int i=0; i < N; i++) {
        cin >> inp;
        buildings.push_back(inp);
    }

    for(int i=0; i < N; i++) {
        int num_visible_buildings = 0;

        // 오른쪽에 보이는 빌딩 수 계산
        // 기울기가 계속 증가하는 경우에 count
        double max_grad = -DBL_MAX;
        for(int j=i+1; j < N; j++) {
            double grad = (buildings[j] - buildings[i]) / static_cast<double>(j - i);
            if(grad > max_grad) {
                num_visible_buildings++;
                max_grad = grad;
            }
        }

        // 왼쪽에 보이는 빌딩 수 계산
        // 기울기가 계속 감소하는 경우에 count
        double min_grad = DBL_MAX;
        for(int j=i-1; j >= 0; j--) {
            double grad = (buildings[j] - buildings[i]) / static_cast<double>(j - i);
            if(grad < min_grad) {
                num_visible_buildings++;
                min_grad = grad;
            }
        }

        if(num_visible_buildings > ans) {
            ans = num_visible_buildings;
        }
    }

    cout << ans << '\n';
}