#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> cards;

int GetNumPacks(int num) {
    int num_packs = 0;
    int num_cards = 0;

    vector<int> card_cnts(500001, 0);

    int left = 0;
    int right = 0;

    while(right < N) {
        // 해당 카드가 이미 들어가있으면
        if(card_cnts[cards[right]] > 0) {
            while(cards[left] != cards[right]) {
                card_cnts[cards[left]]--;
                left++;
                num_cards--;
            }
            left++;

        // 해당 카드가 없으면
        } else {
            card_cnts[cards[right]]++;
            num_cards++;
        }

        if(num_cards == num) {
            num_packs++;
            num_cards = 0;
            
            while(left <= right) {
                card_cnts[cards[left]]--;
                left++;
            }
        }

        right++;
    }

    return num_packs;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    cards = vector<int>(N, 0);

    for(int i=0; i < N; i++) {
        cin >> cards[i];
    }

    int left = 1;
    int right = N;
    int ans = 0;

    while(left <= right) {
        int mid = (left + right) / 2;
        if(GetNumPacks(mid) >= M) {
            ans = max(ans, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ans << '\n';
}