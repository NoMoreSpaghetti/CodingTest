#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int N, K;
vector<int> str_bits;

int count_1(int n) {
    int num_1 = 0;
    while(n != 0) {
        if(n & 1) num_1++;
        n >>= 1;
    }

    return num_1;
}

void print_bit_as_alphabet(int bit) {
    for(int i=0; i < 26; i++) {
        if((1 << i) & bit) {
            cout << (char)(i + 'a');
        }
    }
    cout << '\n';
}

// 0인 위치에 1을 하나씩 추가
int dfs(int init_bit, int reverse_bit_mask) {
    int cur, next_pos_idx, num_1, cnt, answer = 0;

    vector<tuple<int, int, int>> v;
    // 시작 비트, 다음에 1을 추가할 위치, 1의 개수
    // 'a'가 포함되어 있으므로 'b' 부터 검사하면 충분
    v.push_back(make_tuple(init_bit, 1, 5));

    while(v.size()) {
        cur = get<0>(v.back());
        next_pos_idx = get<1>(v.back());
        num_1 = get<2>(v.back());
        v.pop_back();

        if(num_1 == K) {
            cnt = 0;
            //print_bit_as_alphabet(cur);
            for(auto& element : str_bits) {
                if(((~cur) & element) == 0) {
                    cnt++;
                }
            }
            
            if(cnt > answer) {
                answer = cnt;
            }
        } else if(num_1 > K) {
            continue;
        }

        for(int i=next_pos_idx; i < 26; i++) {
            if(((1 << i) & reverse_bit_mask) || ((1 << i) & cur)) {
                continue;
            }
            v.push_back(make_tuple(cur | (1 << i), i + 1, num_1 + 1));
        }
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string inp;
    cin >> N >> K;
    str_bits = vector<int>(N, 0);

    // 초기 비트 설정
    int init_bit = 0, bit;
    char init_chars[5] = {'a', 'n', 't', 'i', 'c'};
    for(auto& init_char : init_chars) {
        init_bit |= (1 << (init_char - 'a'));
    }

    // 등장한 모든 알파벳 마스크
    int bit_mask = init_bit;
    for(int i=0; i < N; i++) {
        cin >> inp;
        bit = init_bit;
        for(int j=4; j < inp.size() - 4; j++) {
            bit |= (1 << (inp[j] - 'a'));
        }
        str_bits[i] = bit;
        bit_mask |= bit;
    }

    // a, n, t, i, c 다섯 문자는 반드시 필요함
    // K가 5보다 작으면 무조건 0개
    if(K < 5) {
        cout << 0 << '\n';
    } else {
        // 실제 등장하는 알파벳의 총 개수보다 K가 큰 경우
        // K는 실제 등장하는 알파벳 개수면 충분하다.
        int max_k = count_1(bit_mask);
        if(K > max_k) {
            K = max_k;
        }
        cout << dfs(init_bit, ~bit_mask) << '\n';
    }
}