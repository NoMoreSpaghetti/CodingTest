#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int X, Y, G;
    string inp1, inp2;

    unordered_map<string, unordered_set<string>> Xs;
    unordered_map<string, unordered_set<string>> Ys;

    cin >> X;

    for(int i=0; i < X; i++) {
        cin >> inp1 >> inp2;
        Xs[inp1].insert(inp2);
        Xs[inp2].insert(inp1);
    }

    cin >> Y;

    for(int i=0; i < Y; i++) {
        cin >> inp1 >> inp2;
        Ys[inp1].insert(inp2);
        Ys[inp2].insert(inp1);
    }

    int num_violated_x = 0;
    int ans = 0;
    vector<string> group(3, "");
    cin >> G;
    for(int i=0; i < G; i++) {
        for(int j=0; j < 3; j++) {
            cin >> group[j];
        }

        for(int j=0; j < 3; j++) {
            if(Xs.find(group[j]) != Xs.end()) {
                int num_xs = Xs[group[j]].size();
                for(int k=1; k < 3; k++) {
                    if(Xs[group[j]].find(group[(j + k) % 3]) != Xs[group[j]].end()) {
                        num_xs --;
                    }
                }
                num_violated_x += num_xs;
            }
        }

        for(int j=0; j < 2; j++) {
            for(int k=j + 1; k < 3; k++) {
                if(Ys.find(group[j]) != Ys.end() && Ys[group[j]].find(group[k]) != Ys[group[j]].end()) {
                    ans++;
                }
            }
        }
    }

    ans += num_violated_x / 2;
    cout << ans << '\n';


}