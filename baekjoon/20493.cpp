#include <iostream>
using namespace std;


int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

int rotate(const int& direction, const string& rot) {
    if(rot == "right") {
        return (direction + 5) % 4;
    } else {
        return (direction + 3) % 4;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, T;
    cin >> N >> T;

    int x = 0, y = 0;
    int direction = 0;
    int rot_time = 100, prev_rot_time = 0;
    string rot;

    for(int i=0; i < N; i++) {
        cin >> rot_time >> rot;
        y += dy[direction] * (rot_time - prev_rot_time);
        x += dx[direction] * (rot_time - prev_rot_time);
        direction = rotate(direction, rot);
        prev_rot_time = rot_time;
    }
    y += dy[direction] * (T - prev_rot_time);
    x += dx[direction] * (T - prev_rot_time);

    cout << x << ' ' << y << '\n';
}