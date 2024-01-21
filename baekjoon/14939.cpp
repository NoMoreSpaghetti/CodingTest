#include <iostream>
#include <bitset>
using namespace std;

bitset<10> input_bulbs[11];
bitset<10> bulbs[11];

int dy[4] = {1, 1, 1, 2};
int dx[4] = {0, -1, 1, 0};

// 십자 모양의 중앙을 누르는게 아닌
// 맨 위를 누르는 것으로 생각
// 따라서 첫번째 줄을 누를 때 0번째 줄에서 누른다고 생각해야 함
// 마지막줄을 누를 때는 그 이전 줄에서 누른다고 생각해야 함
void press(int y, int x) {
    // 누른 위치 전구 반전
    bulbs[y].flip(x);
    // 연결된 위치 전구 반전
    for(int i=0; i < 4; i++) {
        int next_y = y + dy[i];
        int next_x = x + dx[i];
        if(next_y >= 0 && next_y <= 10 && next_x >= 0 && next_x < 10) {
            bulbs[next_y].flip(next_x);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char inp;

    // 0번째 줄 추가
    input_bulbs[0] = 0;
    for(int i=1; i <= 10; i++) {
        input_bulbs[i] = 0;
        for(int j=0; j < 10; j++) {
            cin >> inp;
            if(inp == 'O') {
                input_bulbs[i].set(9 - j, 1);
            }
        }
    }

    int ans = INT32_MAX;
    
    // #O#O#
    // #O#O#
    // ##O##
    // 첫 줄에서만 발생할 수 있는 예시.
    // 두번째, 네번째 전구가 아니라 세번쨰 전구를 눌러야 한다.

    // 0번째 줄을 추가하고 모든 경우의 수 검사

    for(int k=0; k < (1 << 10); k++) {
        // 배열 복사
        copy(begin(input_bulbs), end(input_bulbs), begin(bulbs));
        int num_pressed = 0;
        bulbs[0] = k;

        // 첫번째 줄 검사
        for(int j=0; j < 10; j++) {
            if(bulbs[0][j]) {
                press(0, j);
                num_pressed++;
            }
        }

        // 마지막 줄 이전까지만 검사
        for(int i=1; i < 10; i++) {
            if(bulbs[i].any()) {
                for(int j=0; j < 10; j++) {
                    if(bulbs[i][j]) {
                        press(i, j);
                        num_pressed++;
                    }
                }
            }
        }

        // 마지막 줄 검사
        if(bulbs[10].any()) {
            num_pressed = -1;
        } else {
            ans = min(ans, num_pressed);
        }
    }

    if(ans == INT32_MAX) {
        cout << -1 << '\n';
    } else {
        cout << ans;
    }
}