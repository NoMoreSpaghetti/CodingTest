#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map<char, int> color_map = {{'R', 0}, {'B', 1}, {'Y', 2}, {'G', 3}};

int count_num_bits(int num) {
    int count = 0;
    while(num != 0) {
        if(num & 1) count++;
        num >>= 1;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int score = 0;
    char color;
    int num;
    vector<pair<int, char>> cards;
    int color_bit = 0;
    int num_bit = 0;
    vector<int> nums(10, 0);

    auto update_score = [&](int new_score) {
        score = max(score, new_score);
    };

    for(int i=0; i < 5; i++) {
        cin >> color >> num;
        cards.push_back({num, color});
        nums[num]++;

        color_bit |= (1 << color_map[color]);
        num_bit |= (1 << num);
    }

    sort(cards.begin(), cards.end(), greater<pair<int, char>>());

    vector<bool> rules(10, false);
    int num_of_num_bits = count_num_bits(num_bit);
    int num_of_color_bits = count_num_bits(color_bit);

    // 연속인지 확인
    int num_bit_copy = num_bit;
    while(!(num_bit_copy & 1)) {
        num_bit_copy >>= 1;
    }
    
    if(num_bit_copy == (1 << 5) - 1) {
        rules[5] = true;
        update_score(cards[0].first + 500);
    }
    
    // 다른 조건 확인
    for(int i=1; i < 10; i++) {
        // 숫자 확인
        //---------------------------
        if(nums[i] == 4) {
            // 4장의 숫자가 같은 경우
            rules[2] = true;
            update_score(i + 800);
        } else if(nums[i] == 3) {
            // 3장의 숫자가 같은 경우
            if(num_of_num_bits == 2) {
                // 3장, 2장의 숫자가 같은 경우
                int j = 1;
                for(; j < 10; j++) {
                    if(i != j && nums[j] != 0) {
                        break;
                    }
                }
                rules[3] = true;
                update_score(i * 10 + j + 700);
            } else {
                // 3장, 1장, 1장의 숫자가 같은 경우
                rules[6] = true;
                update_score(i + 400);
            }
        } else if(nums[i] == 2) {
            // 2장, 3장의 숫자가 같은 경우는 이미 위에서 처리
            // 2장, 2장 1장의 숫자가 같은 경우
            if(!rules[7] && num_of_num_bits == 3) {
                int j = i + 1;
                for(; j < 10; j++) {
                    if(i != j && nums[j] == 2) {
                        break;
                    }
                }

                // j는 i보다 무조건 크다.
                rules[7] = true;
                update_score(j * 10 + i + 300);
            } else if(num_of_num_bits == 4) {
                rules[8] = true;
                update_score(i + 200);
            }
        }
    }

    // 색깔 확인
    //-----------------------------
    if(num_of_color_bits == 1) {
        rules[4] = true;
        update_score(cards[0].first + 600);
    }

    if(rules[4] && rules[5]) {
        rules[1] = true;
        update_score(cards[0].first + 900);
    }

    bool meets_at_least_one_rule = false;
    for(int i=1; i <= 8; i++) {
        meets_at_least_one_rule |= rules[i];
    }

    if(!meets_at_least_one_rule) {
        rules[9] = true;
        update_score(cards[0].first + 100);
    }

    cout << score << '\n';
}