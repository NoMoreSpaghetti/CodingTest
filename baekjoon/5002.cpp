#include <iostream>
#include <map>
using namespace std;

// 문제가 이상함
// "정인이는 항상 클럽에 들어가있는 남자와 여자의 차이를 머리속에 계산하고 있어야 한다. 이 차이가 정인이가 기억할 수 있는 값보다 크게 된다면 남은 사람들은 클럽에 입장을 할 수 없게 된다."
// "클럽에 들어가 있는" 인데 줄에 서 있는 사람이 들어가는 경우 차이가 크게 된다면 들여보내지 않음

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int X;
    map<char, int> nums;
    nums.insert({'M', 0});
    nums.insert({'W', 0});
    cin >> X;

    string s;
    cin >> s;

    for(int i=0; i < s.size(); i++) {
        nums[s[i]]++;

        int diff = abs(nums['M'] - nums['W']);
        if(diff > X) {
            // 일단 들여보낸 다음에 차이 계산
            if(i + 1 < s.size() && s[i + 1] != s[i]) {
                // 두 번째 사람이 있고, 들여보낸 사람과 성별이 다를 경우 들여보냄
                nums[s[i + 1]]++;
                i++;
            } else {
                // 두 번째 사람이 없거나 성별이 같으면 방금 들여보낸 사람을 다시 내쫓아야 함 (?)
                nums[s[i]]--;
                break;
            }
        }
    }

    cout << nums['M'] + nums['W'] << '\n';
}