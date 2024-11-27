#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// 좌하단이 0,0
class Square {
public:
    Square(double x1, double y1, double x2, double y2, double h, double v, bool is_black)
    : x1(x1), y1(y1), x2(x2), y2(y2), h(h), v(v), is_black(is_black)
    {
        point_x = (x2 - x1) * h + x1;
        point_y = (y2 - y1) * v + y1;
    }

    bool GetColor(double x, double y) {
        if(x < point_x) {
            if(y < point_y) {
                // left bottom
                if(left_bottom == nullptr) {
                    left_bottom = unique_ptr<Square>(new Square(x1, y1, point_x, point_y, h, v, !is_black));
                }
                return left_bottom->GetColor(x, y);
            } else {
                // left top
                return is_black;
            }
        } else {
            if(y < point_y) {
                // right bottom
                return is_black;
            } else {
                // right top
                if(right_top == nullptr) {
                    right_top = unique_ptr<Square>(new Square(point_x, point_y, x2, y2, h, v, !is_black));
                }
                return right_top->GetColor(x, y);
            }
        }
    }

    double h, v, x1, y1, x2, y2;
    double point_x, point_y;
    bool is_black;
    unique_ptr<Square> left_bottom;
    unique_ptr<Square> right_top;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int case_cnt = 1;
    int n;
    double H, V, h, v, x, y;

    cin >> H >> V >> h >> v >> n;

    while(h != 0) {
        cout << "Case " << case_cnt << ":\n";
        Square root(0, 0, H, V, h, v, true);

        for(int i=0; i < n; i++) {
            cin >> x >> y;
            // cout << x << y << '\n';
            if(root.GetColor(x, y)) {
                cout << "black" << '\n';
            } else {
                cout << "white" << '\n';
            }
        }

        cin >> H >> V >> h >> v >> n;
        case_cnt++;
    }

}