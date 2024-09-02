#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int FF, FS, SF, SS;
    cin >> FF >> FS >> SF >> SS;
    // F로 시작하는 노래는 F 다음에 와야 함
    // S로 시작하는 노래는 S 다음에 와야 함
    // F로 시작하는 노래가 있다면 앨범을 F로 시작해야 함
    // FS가 1개 이상일 경우 FF, SS 모두 포함 가능

    int ans = FF;
    if(FS > 0) {
        ans += SS;
    } else if(FS == 0 && FF == 0) {
        ans += SS;
        if(SF > 0) {
            ans++;
        }
    }

    // FF + (FS + SF) * n + FS + SS + SF + (FS) : FS가 SF보다 1개 많거나 같게
    // FS + SS + (SF + FS) * n + SF + FF + (FS) : FS가 SF보다 1개 많거나 같게
    // SS + SF

    if(FS <= SF) {
        ans += FS * 2;
    } else {
        ans += SF * 2 + 1;
    }
    
    cout << ans << '\n';
}