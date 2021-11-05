#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <math.h>
using namespace std;

int n;
double stars[100][2];
bool visited[100];

double get_dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double prim() {
    memset(visited, false ,sizeof(visited));
    int num_e = -1, cur;
    double dist, next_dist, ans = 0;
    priority_queue<pair<double, int>> pq;
    pq.push(make_pair(0, 0));

    while(num_e < n - 1) {
        cur = pq.top().second;
        dist = -pq.top().first;
        pq.pop();

        if(visited[cur] == false) {
            visited[cur] = true;
            ans += dist;
            num_e++;
            for(int i=0; i < n; i++) {
                if(visited[i] == false) {
                    next_dist = get_dist(stars[cur][0], stars[cur][1], stars[i][0], stars[i][1]);
                    pq.push(make_pair(-next_dist, i));
                }
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i=0; i < n; i++) {
        cin >> stars[i][0] >> stars[i][1];
    }

    cout << fixed;
    cout.precision(2);
    cout << prim() << '\n';
}